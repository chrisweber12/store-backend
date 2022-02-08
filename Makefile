make : driver.cpp Store.cpp Store.hpp Customer.cpp Customer.hpp Product.cpp Product.hpp
	g++ -std=c++11 -o store-backend.exe driver.cpp Store.cpp Customer.cpp Product.cpp
run:
	./store-backend.exe
clean :
	$(info Removing executable)
	rm -f store-backend.exe
