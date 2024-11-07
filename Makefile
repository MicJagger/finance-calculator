default-windows:
	g++ -o finance-calculator.exe *.cpp && finance-calculator.exe
linux:
	g++ -o finance-calculator     *.cpp && ./finance-calculator