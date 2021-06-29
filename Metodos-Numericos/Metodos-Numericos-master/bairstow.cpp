 #include<iostream>
 #include<cmath>
 #include<iomanip>

using namespace std;
int main() {
	int n,m,contadorDivisionSintetica,gradoPolinomio_j,contadorIteraciones,iteracionesMaximas,nx,mx;
	float r,s,e,b1,TOLERANCIA,newsize,r0,s0,b0;
        
	cout << "Introduzca el grado del polinomio: " << "\n";
	cin >> n;
	
	//Polinomio grado 0 no tiene raiz (solo es un entero sin x)
    if(n == 0){
    	cout << "No existen raices en polinomios grado 0" << "\n";
    	return 1;
	} 
	  
    m = n;
	n = n +1;
	contadorDivisionSintetica = contadorIteraciones = 0;

	float Coeficientes[n],Mr[n],Ms[n],Mat1[n],Mat2[m],raizReal[n],raizImaginaria[n],Mat[n];
	float raiz;
        
	//Llenar en 0s las matrices
    for (int i = 0; i < n; i++) {
		Mr[i] = Ms[i] = Mat[i] = raizReal[i] = raizImaginaria[i] = 0;
	}
        
	cout << "Introduzca a continuacion los coeficientes del polinomio" << "\n";
	for (int i = 0; i < n; i++) {
		cout << "Introducir el coeficiente de x^" << -i + (n - 1) << " :" << "\n";
		cin >> Coeficientes[i];
	}
	
	//Polinomio grado 1 (aX + b = 0)no necesita mas que despeje. Se detiene el programa.
    if(n==2){
    	cout << "\n"<<"Raices Calculadas:" << "\n";
    	raiz = ((-1)*Coeficientes[1])/Coeficientes[0];
    	cout << "\n"<<"X0 = " << raiz<<"\n";
    	return 1;
	}
    
	cout << "Introduzca el valor inicial de r : " << "\n";
	cin >> r0;
	cout << "Introduzca el valor inicial de s : " << "\n";
	cin >> s0;
	cout << "Introduzca el valor de Tolerancia para la convergencia: " << "\n";
	cin >> TOLERANCIA;
	cout << "Introduzca numero maximo de iteraciones : " << "\n";
	cin >> iteracionesMaximas;
	b1 = b0 = 1;

	//Se necesita sumarle 2 al contador dado que en cada paso se guardan 2 valores en las raices (j y j+1)
	for (int j = 0; j < 2 * (n - 1); j = j + 2) { 
		b1 = b0 = 1;
		//gradoPolinomio_j es el grado del polinomio a dividir en la iteracion j de la division sintetica
		gradoPolinomio_j = (n - 1) - 2 * contadorDivisionSintetica; 
		nx = n - 1 - 2 * contadorDivisionSintetica;
		mx = nx - 1;
                    
        //Caso en que el polinomio es de grado 2 (x^2). Se puede calcular la raiz sin realizar division sintetica
		if (gradoPolinomio_j <= 2) {
			if (gradoPolinomio_j == 2) {
                //Colocar en arreglos de respuesta real e imaginaria, considerando raiz negativa
				raiz = (Coeficientes[1] * Coeficientes[1]) - (4 * Coeficientes[2]);
				if (raiz < 0) {
					raiz = abs(raiz);
					raizReal[j] = (-Coeficientes[1]) / 2;
					raizReal[j + 1] = (-Coeficientes[1]) / 2;
					raizImaginaria[j] = sqrt(raiz) / 2;
					raizImaginaria[j + 1] = -sqrt(raiz) / 2;
				} 
				else {
					raizReal[j] = ((-Coeficientes[1]) + (sqrt(raiz))) / 2;
					raizReal[j + 1] = ((-Coeficientes[1]) - (sqrt(raiz))) / 2;
					raizImaginaria[j] = 0;
					raizImaginaria[j + 1] = 0;
				}
			}
            //Caso en que el grado del polinomio es menor a 2(x+A=0). La raiz solo es real y es igual a -A
            else {
				raizReal[j] = -Coeficientes[1];
			}
			break;
		}
        //Caso en que el polinomio es mayor a grado 2
        else {
			contadorIteraciones = 0;
			r = r0;
			s = s0;
            //Se regresan a 0 Mr y Ms para preparar para la division sintetica
			for (int i = 0; i <= gradoPolinomio_j; i++) {
				Mr[i] = Ms[i] = Mat1[i] = Mat2[i] = 0; 
			}
                            
            //Se aplica division sintentica para obtener un polinomio de menor grado (-2)
			while (abs(b1) > TOLERANCIA || abs(b0) > TOLERANCIA) {
                //Se realiza la primera division sintetica
				for (int i = 0; i <= gradoPolinomio_j; i++) {
					Mat1[i] = Coeficientes[i] + Mr[i] + Ms[i]; 
					Mr[i + 1] = (-r) * (Mat1[i]);
					Ms[i + 2] = (-s) * (Mat1[i]);
				}
                
				//Se regresan a 0 Mr y Ms para prepara para segunda division sintetica
				for (int i = 0; i <= gradoPolinomio_j; i++) {
					Mr[i] = Ms[i] = 0; 
				}
               
			    //Se realiza la segunda division sintetica
				for (int i = 0; i < gradoPolinomio_j; i++) { 
					Mat2[i] = -Mat1[i] + Mr[i] + Ms[i];
					Mr[i + 1] = (-r) * (Mat2[i]);
					Ms[i + 2] = (-s) * (Mat2[i]);
				}
               
			    //Se calcula el valor de la raiz de iteracion (se acumula en r y s)
				b1 = (((Mat2[mx - 1]) * (-Mat1[nx - 1])) - ((-Mat1[nx]) * (Mat2[mx - 2]))) / (((Mat2[mx - 1]) * (Mat2[mx - 1])) - ((Mat2[mx] + Mat1[nx - 1]) * (Mat2[mx - 2]))); //cramer
				b0 = (((-Mat1[nx]) * (Mat2[mx - 1])) - ((Mat2[mx] + Mat1[nx - 1]) * (-Mat1[nx - 1]))) / (((Mat2[mx - 1]) * (Mat2[mx - 1])) - ((Mat2[mx] + Mat1[nx - 1]) * (Mat2[mx - 2]))); //cramer
				r = r + b1;
				s = s + b0;
				contadorIteraciones++;
				if (contadorIteraciones > iteracionesMaximas) {
					cout << "Fallo en la convergencia" << "\n";
					break;
				}
			}
                            
            //Calcular la raiz
			raiz = (r * r) - (4 * s);
                            
            //Colocar en arreglos de respuesta real e imaginaria, considerando raiz negativa
			if (raiz < 0) {
				raiz = abs(raiz);
				raizReal[j] = -r / 2;
				raizReal[j + 1] = -r / 2;
				raizImaginaria[j] = sqrt(raiz) / 2;
				raizImaginaria[j + 1] = -sqrt(raiz) / 2;
			} 
			else {
				raizReal[j] = ((-r) + (sqrt(raiz))) / 2;
				raizReal[j + 1] = ((-r) - (sqrt(raiz))) / 2;
				raizImaginaria[j] = 0;
				raizImaginaria[j + 1] = 0;
			}
			contadorDivisionSintetica++;
			//tamano del resto del polinomio despues de la doble division sintetica (reduccion en 2 niveles)
			newsize = (n - 1) - (2 * contadorDivisionSintetica);
			//Se pasan los valores de este nuevo polinomio al arreglo de coeficientes para preparar para otra iteracion
			for (int i = 0; i <= newsize; i++) {
				Coeficientes[i] = Mat1[i];
			}
		}
	}
	
	//Imprimir Raices calculadas
	cout << "\n"<<"Raices Calculadas:" << "\n";
	
	for (int i = 0; i < n - 1; i++) {
		//Checar si no tiene parte imaginaria (imprimir solo la parte real)
		if (raizImaginaria[i] == 0) {
			cout << "X" << i << " = " << raizReal[i] << "\n";
		} 
		//Tiene parte imaginaria (imprimir ambas partes de la raiz)
		else {
			cout << "X" << i << " = " << raizReal[i];
			//Raiz imaginaria negativa (el numero ya tiene el caracter '-'
			if (raizImaginaria[i] < 0) {
				//Cuando la parte imaginaria es == -1 se imprime solo '-i'
				if (raizImaginaria[i] == -1) {
					cout << "-i" << "\n";
				} 
				else {
					cout << raizImaginaria[i] << "i" << "\n";
				}
			} 
			//Raiz imaginaria positiva (concatenamos caracter '+')
			else {
				//Cuando la parte imaginaria es == 1 se imprime solo '+i'
				if (raizImaginaria[i] == 1) {
					cout << "+i" << "\n";
				} 
				else {
					cout << "+" << raizImaginaria[i] << "i" << "\n";
				}
			}
		}
	}
}
