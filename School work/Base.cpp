struct Base {
	int v;

	Base(int v) : v(v) {}
	virtual ~Base() = default;

	virtual Base& operator=(const Base& other) {
		v = other.v;
		return *this;
	}
};

struct Derived : public Base {
	int w;

	Derived(int v, int w) : Base(v), w(w) {}

	Derived& operator=(const Base& other) override {
		Base::operator=(other);
		const Derived* d = dynamic_cast<const Derived*>(&other);
		if (d != nullptr) {
			w = d->w;
		}
		return *this;
	}
};