bool Rectangle::contains(Rectangle &r) const {
	if(r.x < x || x+w < r.x+r.w) {
		return false;
	}
	if(r.y < y || y+h < r.y+r.h) {
		return false;
	}
	return true;
}
