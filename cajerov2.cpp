#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

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

int main(){
Cuenta cuentas[3];
cuentas[0].numero=1001;
cuentas[0].titular="Diego Barraza";
cuentas[0].saldo=5000.00;
cuentas[1].numero=1002;
cuentas[1].titular="Wolfgang Garcia";
cuentas[1].saldo=3500.00;
cuentas[2].numero=1003;
cuentas[2].titular="Hector Morales";
cuentas[2].saldo=7200.00;
int opcion=0;
int miCuenta;
cout<<"===================================="<<endl;
cout<<"  BIENVENIDO AL CAJERO AUTOMATICO  "<<endl;
cout<<"===================================="<<endl;
cout<<"\nSelecciona tu cuenta:"<<endl;
for(int i=0;i<3;i++){
cout<<i<<". Cuenta "<<cuentas[i].numero<<" - "<<cuentas[i].titular<<endl;
}
cout<<"Ingresa el numero (0, 1 o 2): ";
cin>>miCuenta;
if(miCuenta<0 || miCuenta>2){
cout<<"Cuenta invalida. Adios!"<<endl;
return 1;
}
cout<<"\nHola "<<cuentas[miCuenta].titular<<"!"<<endl;
while(opcion!=5){
try{
mostrarMenu();
cin>>opcion;
if(cin.fail()){
cin.clear();
cin.ignore(10000,'\n');
throw invalid_argument("Opcion invalida. Debes ingresar un numero");
}
switch(opcion){
case 1:
consultarSaldo(cuentas,miCuenta);
break;
case 2:
retirarDinero(cuentas,miCuenta);
break;
case 3:
depositarDinero(cuentas,miCuenta);
break;
case 4:
transferirDinero(cuentas,miCuenta,3);
break;
case 5:
cout<<"\nGracias por usar el cajero. Adios!"<<endl;
break;
default:
cout<<"\nOpcion invalida. Intenta de nuevo."<<endl;
break;
}
}
catch(invalid_argument& e){
cout<<"\nError: "<<e.what()<<endl;
cin.clear();
cin.ignore(10000,'\n');
}
catch(runtime_error& e){
cout<<"\nError: "<<e.what()<<endl;
}
catch(out_of_range& e){
cout<<"\nError: "<<e.what()<<endl;
}
catch(...){
cout<<"\nError desconocido. Intenta de nuevo."<<endl;
}
}
return 0;
}
