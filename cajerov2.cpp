
int main(){
//arreglo de cuentas
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

//seleccionar cuenta
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

//menu principal
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
