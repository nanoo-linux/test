#pragma once

class iEventShooter
{
	public:
		iEventShooter();
		virtual ~iEventShooter();
		void do_bytes(const char *, ssize_t);
};
