#include <iostream> 

using namespace std; 



class Motor { 
	
public: 
	
	Motor(int cilindrada, int potencia) : _cilindrada(cilindrada), _potencia(potencia) {} 
	
	
	
	int getCilindrada() const { return _cilindrada; } 
	
	void setCilindrada(int cilindrada) { _cilindrada = cilindrada; } 
	
	
	
	int getPotencia() const { return _potencia; } 
	
	void setPotencia(int potencia) { _potencia = potencia; } 
	
	
	
private: 
		
		int _cilindrada; 
		
		int _potencia; 
		
}; 



class Coche { 
	
public: 
	
	Coche(Motor* motor) : _motor(motor) {} 
	
	
	
	~Coche() { delete _motor; } 
	
	
	
	Motor* getMotor() { return _motor; } 
	
	
	
private: 
		
		Motor* _motor; 
		
}; 



bool validarCilindrada(int cilindrada) { 
	
	if (cilindrada <= 0) { 
		
		cout << "Error: La cilindrada debe ser un valor positivo." << endl; 
		
		return false; 
		
	} 
	
	
	
	if (cilindrada > 10000) { 
		
		cout << "Error: La cilindrada no puede ser mayor a 10000." << endl; 
		
		return false; 
		
	} 
	
	
	
	return true; 
	
} 



bool validarPotencia(int potencia) { 
	
	
	
	if (potencia <= 0) { 
		
		cout << "Error" << endl; 
		
		return false; 
		
	} 
	
	
	
	if (potencia > 10000000) { 
		
		cout << "Error" << endl; 
		
		return false; 
		
	} 
	
	
	
	return true; 
	
} 



int main() { 
	
	int cilindrada; 
	
	int potencia;    
	
	do { 
		
		cout << "Ingrese la cilindrada del motor: "; 
		
		cin >> cilindrada; 
		
	} while (!validarCilindrada(cilindrada)); 
	
	
	
	do { 
		
		cout << "Ingrese la potencia del motor: "; 
		
		cin >> potencia; 
		
	} while (!validarPotencia(potencia)); 
	
	
	
	Motor* motor = new Motor(cilindrada, potencia); 
	
	
	
	Coche* coche = new Coche(motor); 
	
	
	
	delete coche; 
	
	
	
	return 0; 
	
} 
