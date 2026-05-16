struct Base {
	int v;

	Base(int tv) : v{tv} {}

	virtual ~Base() = default;

	virtual Base& operator=(const Base& other) {
		this->v = other.v;
		return *this;
	}
};

struct Derived : public Base {
	int w;

	Derived(int tv, int tw) : Base{tv}, w{tw} {}

	Derived& operator=(const Base& other) override {
		v = other.v;
		if (const Derived* p = dynamic_cast<const Derived*>(&other)) {
			w = p->w;
		}
		return *this;
	}
};