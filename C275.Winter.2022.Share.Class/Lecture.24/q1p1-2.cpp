struct point {
	int x, y;
	bool onaxis() const;
};

bool point::onaxis() const {
	return x == 0  || y == 0;
}
