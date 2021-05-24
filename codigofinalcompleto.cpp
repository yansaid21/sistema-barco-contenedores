#include <iostream>
using namespace std;

int const filas=4;
int const columnas=5;
void limpiarMatrices (bool disponibilidad[filas][columnas], float precios[filas][columnas],float peso[filas][columnas],float precios2[filas][columnas]);
void nombrePuertosIniciales (int puertos,string vector[],string auxiliarLetras);
void mostrarNombresIniciales (int puertos,string vector[]);
void mostrarCoordenadasDisponibles (bool matriz[filas][columnas]);
void imprimirMatrizBooleana (bool matriz[filas][columnas]);
void imprimirMatrizDecimal (float matriz[filas][columnas]);
void imprimirMatrizString (string matriz[filas][columnas]);
void limpiarMatricess (float precios[filas][columnas]);
void limpiarVector (int vectorContenedores[]);
void ordenamientoBurbuja (int vector[],string contenedores[], int puertos);
void imprimirVector (string vectorContenedores[],int vectorNum[],int puertos);
void nombresPremium (string marca[filas][columnas],bool disponibilidad[filas][columnas]);
float promedioPeso (bool disponibilidad[filas][columnas],float peso[filas][columnas]);
int filaMayor (float peso[filas][columnas]);
int columnaMenor (float peso[filas][columnas]);
int buscaMercancia(string tipodemercancia[filas][columnas]);
float promedioPuerto(string puertodecarga[filas][columnas],float peso [filas][columnas]);
float pesoMayorPeso (float peso[filas][columnas], string marca [filas][columnas]);
string pesoMayorMarca (float peso[filas][columnas], string marca [filas][columnas]);
float pesoLivianoPeso (float peso[filas][columnas], string marca [filas][columnas]);
string pesoLivianoMarca (float peso[filas][columnas], string marca [filas][columnas]);
void buscador (string marca[filas][columnas],float precios2[filas][columnas]);


int main (){
	
	 
    
	float contador=0.0;
	float valorBarco=0.0;
	float preciosacumulados=0.0;//acumulador
	
	int vectorContenedores[20];
	int vectorNumContenedores[20];
	
	string auxiliarLetras;
	
	//llenar los contenedores dependiendo si hay coordenadas disponibles o no
	
	float peso [filas][columnas];//matriz
	float precios[filas][columnas];//matriz
	string marca [filas][columnas];//matriz
	bool disponibilidad [filas][columnas];//matriz
	string tipodemercancia [filas][columnas];//matriz
	string puertodecarga [filas][columnas];//matriz
	float precios2[filas][columnas];//matriz
	//limpiar la matriz
    limpiarMatrices(disponibilidad,peso,precios,precios2);
    limpiarVector(vectorNumContenedores);
	
	//variable numero contenedores
	int numerocontenedores =0;
	
	//preguntar cantidad de puertos
	int puertos=0;
	cout<<"ingrese la cantidad de puertos a visitar"<<endl;
	cin>>puertos;
	string puertoInicial[puertos];//vector
	
	//preguntar nombre puertos
    nombrePuertosIniciales (puertos,puertoInicial,auxiliarLetras);
    //mostrar nombres puertos
    mostrarNombresIniciales (puertos,puertoInicial);
    int coordenadaFila=-1;
    int coordenadaColumna=-1;
	//for segun los puertos
	for(int z=0;z<puertos;z++){
		
	//mostrar las celdas disponibles
	mostrarCoordenadasDisponibles(disponibilidad);
	
	//preguntar por la cantidad de contenedores
	cout<<"ingrese la cantidad de contenedores"<<endl;
	cin>>numerocontenedores;
	vectorNumContenedores[z]=numerocontenedores;
	string premium [numerocontenedores];
	string economico[numerocontenedores];
	
	
	
	for(int i=0;i<numerocontenedores;i++){
	do{
		cout<<"Ingrese coordenada fila"<<endl;
		cin>>coordenadaFila;
		cout<<"Ingrese coordenada columna"<<endl;
		cin>>coordenadaColumna;
		if(coordenadaFila>=0 && coordenadaFila<filas && coordenadaColumna>=0 && coordenadaColumna<columnas){
			if (disponibilidad[coordenadaFila][coordenadaColumna]==1){
			//celda disponible
			//actualizar matriz de disponibilidad
			disponibilidad[coordenadaFila][coordenadaColumna]=0;
			//preguntar informacion del contenedor Marca, peso, puerto origen y tipo artículo
			cout<<"ingrese peso del contenedor"<<endl;
			cin>>peso[coordenadaFila][coordenadaColumna];
			cout<<"ingrese la marca de la empresa"<<endl;
			cin>>marca[coordenadaFila][coordenadaColumna];
			cout<<"tipos de articulos:"<<endl;
			cout<<"Tipo A: Alimentos"<<endl;
			cout<<"Tipo B: Dispositivos electronicos"<<endl;
			cout<<"Tipo C: Ropa y demas textiles"<<endl;
			cin>> tipodemercancia[coordenadaFila][coordenadaColumna];
			cout<<"ingrese el puerto de carga nuevamente"<<endl;
			cin>>puertodecarga[coordenadaFila][coordenadaColumna];
			//puertodecarga[coordenadaFila][coordenadaColumna]=auxiliarLetras;
			if ((coordenadaFila>=1 && coordenadaFila<=3) && (coordenadaColumna>=1 && coordenadaColumna<=2)){
				precios[coordenadaFila][coordenadaColumna]=300;
				precios2[coordenadaFila][coordenadaColumna]=precios[coordenadaFila][coordenadaColumna];
			} else {
				precios[coordenadaFila][coordenadaColumna]=100;
				precios2[coordenadaFila][coordenadaColumna]=precios[coordenadaFila][coordenadaColumna];
			}
		}
	else{ cout<<"coordenada invalida, repita el proceso"<<endl;
	disponibilidad[coordenadaFila][coordenadaColumna]=1;
	i=i-1;
	}
	}
	else{ cout<<"coordenada fuera de parametros"<<endl;
	disponibilidad[coordenadaFila][coordenadaColumna]=1;
	}
	}while(disponibilidad[coordenadaFila][coordenadaColumna]==1);//0 porque es mientras esté llenada la coordenada
	
	}
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			if (disponibilidad[i][j]==0){
				contador++;
				valorBarco=(contador/20)*100;
			}
		}
	}
	cout<<"el porcentaje actual del barco es: "<<valorBarco<<"%"<<endl;
	
	preciosacumulados=0.0;
	
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			preciosacumulados=preciosacumulados+precios[i][j];
		}
	}
		cout<<"el dinero recaudado en el puerto es: "<<preciosacumulados<<endl;
		for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			precios[i][j]=0;
		}
	}
		
	}
	//promedio
	float promedio=promedioPeso (disponibilidad,peso);
	cout<<"promedio: "<<promedio<<endl;
	//fila con mas carga
	int filaMasPeso=filaMayor (peso);
	cout<<"fila con mas carga: "<<filaMasPeso<<endl;
	//columna con menor carga
	int columnaMenosPeso=columnaMenor (peso);
	cout<<"columna con menos carga: "<<columnaMenosPeso<<endl;
	//cantidad de contenedor por tipo de mercancia
	int cantidadContenedor=buscaMercancia (tipodemercancia);
	cout<<"De ese tipo de mercancia, hay "<<cantidadContenedor<<endl;
	//promedio de peso por puerto
	float promediador=promedioPuerto(puertodecarga,peso);
	cout<<"el promedio del puerto es :"<<promediador <<endl;
	//empresa con el contendor de mas peso
	float empresaMasPeso=pesoMayorPeso(peso,marca);
	string empresaMasPesoMarca=pesoMayorMarca(peso,marca);
	cout<<"la marca con el peso mayor es: "<<empresaMasPesoMarca<<endl;
	cout<<"el peso es: "<<empresaMasPeso<<endl;
	//empresa con el contenedor de menos peso
	float empresaMenosPeso=pesoLivianoPeso (peso,marca);
	string empresaMenosPesoMarca=pesoLivianoMarca (peso,marca);
	cout<<"la marca con el peso mas liviano es: "<<empresaMenosPesoMarca<<endl;
	cout<<"el peso es: "<<empresaMenosPeso<<endl;
	//nombre empresa,contenedores por zona,valor a pagar
	buscador (marca,precios2);
	
	//imprimir matrices
	cout<<"disponibilidad"<<endl;
	imprimirMatrizBooleana (disponibilidad);
	cout<<"peso"<<endl;
	imprimirMatrizDecimal (peso);
	cout<<"tipo de articulo"<<endl;
	imprimirMatrizString (tipodemercancia);
	cout<<"marca"<<endl;
	imprimirMatrizString (marca);
	cout<<"puerto de carga"<<endl;
	imprimirMatrizString (puertodecarga);
	//cout<<"precios"<<endl;
	//imprimirMatrizDecimal(precios);
	limpiarMatricess(precios);
	cout<<"marcas"<<endl;
	nombresPremium (marca,disponibilidad);
	ordenamientoBurbuja(vectorNumContenedores,puertoInicial,puertos);
	cout<<"vector"<<endl;
	imprimirVector (puertoInicial,vectorNumContenedores,puertos);
	
	
	return 0;
}

void limpiarMatrices (bool disponibilidad[filas][columnas], float precios[filas][columnas],float peso[filas][columnas],float precios2[filas][columnas]){
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			disponibilidad[i][j]=1;
			peso[i][j]=0;
			precios[i][j]=0;
		}
	}
}
void limpiarMatricess (float precios[filas][columnas]){
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			precios[i][j]=0;
		}
	}
}
void limpiarVector (int vectorContenedores[]){
	for (int i=0;i<20;i++){
		vectorContenedores[i]=0;
	}
}
void nombrePuertosIniciales (int puertos,string vector[],string auxiliarLetras){
		for (int i=0;i<puertos;i++){
		cout<<"ingrese nombre del puerto "<<endl;
		cin>>auxiliarLetras;
		vector[i]=auxiliarLetras;
	    }
}
void mostrarNombresIniciales (int puertos,string vector[]){
	for (int i=0;i<puertos;i++){
		cout<<"los puertos iniciales son: "<<vector[i]<<endl;
	}
}
void mostrarCoordenadasDisponibles (bool matriz[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if (matriz[i][j]==1){
    		 cout<<"Los puertos "<<i<<","<<j<<" estan disponibles"<<endl;
    	    }
		}
	}
}
void imprimirMatrizBooleana (bool matriz[filas][columnas]){
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void imprimirMatrizDecimal (float matriz[filas][columnas]){
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void imprimirMatrizString (string matriz[filas][columnas]){
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void imprimirVector (string vectorContenedores[],int vectorNum[],int puertos){
	for (int i=0;i<puertos;i++){
		cout<<vectorContenedores[i]<<"->"<<vectorNum[i]<<endl;;
	}
}

void nombresPremium (string marca[filas][columnas],bool disponibilidad[filas][columnas]){
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			if (disponibilidad[i][j]==0){
			if ((i>=1 && i<=3) && (j>=1 && j<=2)){
				cout<<"marca premium "<<marca[i][j]<<"\t";
			} else {
				cout<<"marca economica "<<marca[i][j]<<"\t"<<endl;
			}
		}
		}
		cout<<endl;
	}
}
void ordenamientoBurbuja (int vector[],string contenedores[], int puertos){

int auxnum=0;
string auxlet;
for(int i=0;i<puertos;i++){
	for(int j=0;j<puertos;j++){
		if(vector[i]>vector[j]){
			auxnum=vector[j];
			vector[j]=vector[i];
			vector[i]=auxnum;
			
			auxlet=contenedores[j];
			contenedores[j]=contenedores[i];
			contenedores[i]=auxlet;
		}
	}

	}
}
float promedioPeso (bool disponibilidad[filas][columnas],float peso[filas][columnas]){
	int acumuladorPeso=0;
	float promedio=0.0;
	int contadorPeso=0;
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			if (disponibilidad[i][j]==0){
				acumuladorPeso=acumuladorPeso+peso[i][j];
				contadorPeso++;
			}
		}
	}
	promedio=acumuladorPeso/contadorPeso;
	return promedio;
}
int filaMayor (float peso[filas][columnas]){
	int mayor=INT_MIN;
	float acumuladorFila=0.0;
	int filaMayor=-1;
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			acumuladorFila=acumuladorFila+peso[i][j];
		}
		if (acumuladorFila>mayor){
			mayor=acumuladorFila;
			filaMayor=i;
		}
		acumuladorFila=0.0;
	}
	return filaMayor;
}
int columnaMenor (float peso[filas][columnas]){
	int menor=INT_MAX;
	float acumuladorColumna=0.0;
	int columnaMenor=-1;
	for (int j=0;j<columnas;j++){
		for (int i=0;i<filas;i++){
			acumuladorColumna=acumuladorColumna+peso[i][j];
		}
		if (acumuladorColumna<menor){
			menor=acumuladorColumna;
			columnaMenor=j;
		}
		acumuladorColumna=0.0;
	}
	return columnaMenor;
}
int buscaMercancia(string tipodemercancia[filas][columnas]){
	string buscadorLetras="";
	int contador=0;
	cout<<"ingrese el tipo de mercancia"<<endl;
			cin>>buscadorLetras;
	for(int i =0;i<filas;i++){
		for(int j=0;j<columnas;j++){	
			if(tipodemercancia[i][j]==buscadorLetras){
				contador++;	
			}
		}
	}
	return contador;
}
 float promedioPuerto(string puertodecarga[filas][columnas],float peso [filas][columnas]){
	int acumulador=0;
	int contador=0;
	int acumuladorPeso=0;
	float promedio=0.0;
	string buscadorLetras="";
	cout<<"ingrese el puerto de origen"<<endl;
	cin>>buscadorLetras;
	for(int i =0;i<filas;i++){
		for(int j=0;j<columnas;j++){	
			if(puertodecarga[i][j]==buscadorLetras){
				acumulador=peso[i][j];
				acumuladorPeso=acumuladorPeso+acumulador;
				contador++;
			}
		}
	}
	promedio=acumuladorPeso/contador;
	return promedio;
}
float pesoMayorPeso (float peso[filas][columnas], string marca [filas][columnas]){
	int menor=INT_MIN;
	int coordenadaFila=-1;
	int coordenadaColumna=-1;
	string marcaSeleccionada="";
	for (int i=0;i<filas;i++){
		coordenadaFila++;
		for (int j=0;j<columnas;j++){
			coordenadaColumna++;
			if (peso[i][j]>menor){
				menor=peso[i][j];
				marcaSeleccionada=marca[i][j];
			}
			
		}
	}
	return menor;
}
string pesoMayorMarca (float peso[filas][columnas], string marca [filas][columnas]){
	int menor=INT_MIN;
	int coordenadaFila=-1;
	int coordenadaColumna=-1;
	string marcaSeleccionada="";
	for (int i=0;i<filas;i++){
		coordenadaFila++;
		for (int j=0;j<columnas;j++){
			coordenadaColumna++;
			if (peso[i][j]>menor){
				menor=peso[i][j];
				marcaSeleccionada=marca[i][j];
			}
			
		}
	}
	
	return marcaSeleccionada;
}
float pesoLivianoPeso (float peso[filas][columnas], string marca [filas][columnas]){
	int mayor=INT_MAX;
	string marcaSeleccionada="";
	for (int i=0;i<filas;i++){
		
		for (int j=0;j<columnas;j++){
			
			if ((peso[i][j]<mayor)&&(peso[i][j]>0)){
				mayor=peso[i][j];
				marcaSeleccionada=marca[i][j];
			}
			
		}
	}
	return mayor;
}
string pesoLivianoMarca (float peso[filas][columnas], string marca [filas][columnas]){
	int mayor=INT_MAX;
	string marcaSeleccionada="";
	for (int i=0;i<filas;i++){
		
		for (int j=0;j<columnas;j++){
			
			if ((peso[i][j]<mayor)&&(peso[i][j]>0)){
				mayor=peso[i][j];
				marcaSeleccionada=marca[i][j];
			}
			
		}
	}
	return marcaSeleccionada;
}
void buscador (string marca[filas][columnas],float precios2[filas][columnas]){
	string buscadorMarcas="";
	int dinero=0;
	int contador=0;
	int contadorPremium=0;
	int contadorEconomico=0;
	int dineroSuma=0;
	cout<<"ingrese marca"<<endl;
	cin>>buscadorMarcas;
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			if (marca[i][j]==buscadorMarcas){
				dinero=precios2[i][j];
				dineroSuma=dineroSuma+dinero;
				contador++;
				if (precios2[i][j]==300){
					contadorPremium++;
				} else if (precios2[i][j]==100){
					contadorEconomico++;
				}
					
				}
			}
			
		}
	
	cout<<"la marca "<<buscadorMarcas<<" tiene "<<contador<<endl;
	cout<<" contenedores en premium (300) "<<contadorPremium<<", contenedores en economico (100) "<<contadorEconomico<<endl;
	cout<<"el precio a pagar es "<<dineroSuma<<endl;
}
