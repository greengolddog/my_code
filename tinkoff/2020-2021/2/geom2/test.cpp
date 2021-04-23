class A;

class B {
	A to_A();
};

class A {
public:
	A() = default;
private:
	B c;
	B to_B();
};

A B::to_A() {
	return A();
}

B A::to_B() {
	return c;
}

int main() {
	
}

