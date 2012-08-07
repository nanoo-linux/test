#include "SerialPort.hpp"
#include <unistd.h>

SerialPort::SerialPort(const char *pn, iEventShooter &es)
: ev_(es)
{
	if (!open_df()) {
		goto err1;
	}

	if (!open_port(pn)) {
		goto err2;
	}

	int ret;
	void *thread_arg = static_cast <void *> (this);
	ret = pthread_create(threadID_, NULL, thread_starter, thread_arg);
	if (ret < 0) {
		goto err3;
	}
	
	return;
	
err3:
	close_port();
err2:
	close_df();
err1:
	throw SerialPortException;
}

SerialPort::~SerialPort()
{
	write(df_[1], 1, '0');
	pthread_join(threadID_, NULL);
	close_port();
	close_df();
}

void *SerialPort::thread_starter(void *th_)
{
	(static_cast <SerialPort *> (th_))->thread_main();
	return 0;
}

void SerialPort::thread_main()
{
	int max_fd;
	int df = df_[0];
	int ret;
	fd_set fds;
	while (true) {
		FD_ZERO(&fds);
		FD_SET(df, &fds);
		FD_SET(sf_, &fds);
		max_fd = (sf_ > df ? sf_ : df) +1;
		ret = select(max_fd, fds, NULL, NULL, NULL);
		if (ret > 0) {
			if (FD_ISSET(sf_, &fds)) {
				read_port();
			} else if (FD_ISSET(df, &fds)) {
				return;
			}
		} else { // ret < 0
			//TODO:
		}
	}
}

bool SerialPort::open_port(const char *)
{
	return false;
}

void SerialPort::close_port()
{
	close(sf_);
}

bool SerialPort::open_df()
{
	int ret;
	ret = pipe(df_);
	if (ret < 0) {
		return false;
	}
	return true;
}

void SerialPort::close_df()
{
	close(df_[0]);
	close(df_[1]);
}

void SerialPort::read_port()
{
	ssize_t ret;
	//TODO: 200 must be extracted from the sf_ descriptor.
	Array <char> buffer(200);
	ret = read(sf_, buffer.get(), 200);
	if (ret > 0) {
		ev_.do_bytes(buffer.get(), ret);
	}
}
