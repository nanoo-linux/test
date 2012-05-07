#pragma once

class PointCharge
{
	public:
		PointCharge(int x, int y, double c);
		int x() const;
		int y() const;
		double charge() const;
	private:
		int x_;
		int y_;
		double charge_;
};
