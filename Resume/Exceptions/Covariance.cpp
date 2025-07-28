
class Base {
public:
	class BaseException {};
	class DerivedException : public BaseException {};
	virtual void f() throw(DerivedException) {
		throw DerivedException();
	}
	virtual void g() throw(BaseException) {
		throw BaseException();
	}
};

class Derived : public Base {
public:
	void f() throw(BaseException) {
		throw BaseException();
	}
	virtual void g() throw(DerivedException) {
		throw DerivedException();
	}
};