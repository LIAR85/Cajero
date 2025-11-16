#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

//estructura de cuentas
struct Cuenta{
int numero;
string titular;
double saldo;
};

void mostrarMenu(){
cout<<"\n===== CAJERO AUTOMATICO ====="<<endl;
cout<<"1. Consultar saldo"<<endl;
cout<<"2. Retirar dinero"<<endl;
cout<<"3. Depositar dinero"<<endl;
cout<<"4. Transferir dinero"<<endl;
cout<<"5. Salir"<<endl;
cout<<"Elige una opcion: ";
}

//funcion consultar saldo
void consultarSaldo(Cuenta cuentas[],int numCuenta){
cout<<"\n--- CONSULTA DE SALDO ---"<<endl;
cout<<"Cuenta: "<<cuentas[numCuenta].numero<<endl;
cout<<"Titular: "<<cuentas[numCuenta].titular<<endl;
cout<<"Saldo actual: $"<<cuentas[numCuenta].saldo<<endl;
}

void retirarDinero(Cuenta cuentas[],int numCuenta){
double monto;
cout<<"\n--- RETIRO DE DINERO ---"<<endl;
cout<<"Saldo actual: $"<<cuentas[numCuenta].saldo<<endl;
cout<<"Cuanto dinero quieres retirar? $";
cin>>monto;

if(monto<=0){
throw invalid_argument("El monto debe ser mayor a cero");
}

if(monto>cuentas[numCuenta].saldo){
throw runtime_error("Saldo insuficiente");
}

cuentas[numCuenta].saldo=cuentas[numCuenta].saldo-monto;
cout<<"Retiro exitoso!"<<endl;
cout<<"Nuevo saldo: $"<<cuentas[numCuenta].saldo<<endl;
}

//depositar
void depositarDinero(Cuenta cuentas[],int numCuenta){
double monto;
cout<<"\n--- DEPOSITO DE DINERO ---"<<endl;
cout<<"Saldo actual: $"<<cuentas[numCuenta].saldo<<endl;
cout<<"Cuanto dinero quieres depositar? $";
cin>>monto;

if(monto<=0){
throw invalid_argument("El monto debe ser mayor a cero");
}
cuentas[numCuenta].saldo=cuentas[numCuenta].saldo+monto;
cout<<"Deposito exitoso!"<<endl;
cout<<"Nuevo saldo: $"<<cuentas[numCuenta].saldo<<endl;
}

void transferirDinero(Cuenta cuentas[],int numCuenta,int totalCuentas){
double monto;
int cuentaDestino;

cout<<"\n--- TRANSFERENCIA DE DINERO ---"<<endl;
cout<<"Saldo actual: $"<<cuentas[numCuenta].saldo<<endl;

cout<<"\nCuentas disponibles para transferir:"<<endl;
for(int i=0;i<totalCuentas;i++){
if(i!=numCuenta){
cout<<"  "<<i<<". Cuenta "<<cuentas[i].numero<<" - "<<cuentas[i].titular<<endl;
}
}

cout<<"A que cuenta quieres transferir? (numero de 0 a "<<totalCuentas-1<<"): ";
cin>>cuentaDestino;

if(cuentaDestino<0 || cuentaDestino>=totalCuentas){
throw out_of_range("Cuenta destino invalida");
}

if(cuentaDestino==numCuenta){
throw invalid_argument("No puedes transferir a tu misma cuenta");
}

cout<<"Cuanto dinero quieres transferir? $";
cin>>monto;

if(monto<=0){
throw invalid_argument("El monto debe ser mayor a cero");
}

if(monto>cuentas[numCuenta].saldo){
throw runtime_error("Saldo insuficiente");
}

cuentas[numCuenta].saldo=cuentas[numCuenta].saldo-monto;
cuentas[cuentaDestino].saldo=cuentas[cuentaDestino].saldo+monto;

cout<<"Transferencia exitosa!"<<endl;
cout<<"Nuevo saldo: $"<<cuentas[numCuenta].saldo<<endl;
cout<<"Saldo de cuenta destino: $"<<cuentas[cuentaDestino].saldo<<endl;
}
