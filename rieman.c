# include <stdio.h>
# include <math.h>

/*
Este programa calcula integrais usando somas de rieman com a
regra do ponto medio
Autor: Wellisson Galvao Lopes
*/

double integralPolinomial(double b, double a, double n,double grau);
double integralTrigonometrica(double b, double a, double n, double grau);
double integralTrigonometricaInversa(double b,double a, double n, double grau);
double integralTrigonometricaHiperbolica(double b,double a, double n, double grau);
double integralTrigonometricaHiperbolicaInversa(double b,double a, double n, double grau);
double mathToRadians(double a);


int main(int argc, char const **argv){
    int termos = 0,i,op;
    double a,b,n,g,coef,dX,sig,aux=0.0;
    printf("digite o intervalo [a,b] e o numero de intervalos:\n");
    scanf("%lf %lf %lf",&a,&b,&n);
    dX = (b-a)/n;
    printf("digite a quantidade de termos:\n");
    scanf("%d",&termos);
    for(i = 0; i < termos; i++){
        printf("Selecione o tipo de função:\n1 - Polinomial\n2 - Trigonometrica\n3 - Trigonometrica Inversa\n4 - Hiperbolicas\n5 - Hiperbolica Inversa\n");
        scanf("%d",&op);
          if (op == 1) {
            printf("Digite o grau e o coeficiente:\n");
            scanf("%lf %lf",&g,&coef);
            sig = integralPolinomial(b,a,dX,g);
          } else if (op == 2) {
            printf("Digite o grau e o coeficiente:\n");
            scanf("%lf %lf",&g,&coef);
            sig = integralTrigonometrica(b,a,dX,g);
          } else if(op == 3){
            printf("Digite o grau e o coeficiente:\n");
            scanf("%lf %lf",&g,&coef);
            sig = integralTrigonometricaInversa(b,a,dX,g);
          } else if (op == 4) {
            printf("Digite o grau e o coeficiente:\n");
            scanf("%lf %lf",&g,&coef);
            sig = integralTrigonometricaHiperbolica(b,a,dX,g);
          } else if (op == 5) {
            printf("Digite o grau e o coeficiente:\n");
            scanf("%lf %lf",&g,&coef);
            sig = integralTrigonometricaHiperbolicaInversa(b,a,dX,g);
          }
          sig = coef * sig;
          aux += sig;
    }
    if (aux == 0.0) {
      printf("0\n");
    }else{
        printf("%lf\n",aux);
    }
    return 0;
}


double integralPolinomial(double b, double a, double n, double grau){
    double soma = 0.0,p = 0.0;
    if(a == b){
        return p;
    }
    while(a <= b){
        soma = n*(pow(a,grau));
        a=a+n;
        p=p+soma;
    }
   return p;
}

double integralTrigonometrica(double b, double a, double n,double grau){
     double soma = 0.0,p = 0.0;
     int op;
     printf("Selecione o tipo de funcao:\n1 - Seno\n2 - Cosseno\n3 - Tangente\n4 - Secante\n5 - Cossecante\n6 - Cotangente\n");
     scanf("%d",&op);
     if(a == b){
        return p;
    }
    a = mathToRadians(a);
    b = mathToRadians(b);
    while(a <= b){
        if (op == 1) {
          soma = n*(pow(sin(a),grau));
        } else if (op == 2) {
          soma = n*(pow(cos(a),grau));
        }else if(op == 3){
          soma = n*(pow(tan(a),grau));
        }else if(op == 4){
          soma = n*(pow((1/cos(a)),grau));
        }else if (op == 5) {
          soma = n*(pow((1/sin(a)),grau));
        }else if (op == 6) {
          soma = n*(pow((1/tan(a)),grau));
        }
        a = a + n;
        p = p + soma;
    }
    return p;
}

double integralTrigonometricaInversa(double b,double a, double n, double grau){
  double soma = 0.0,p = 0.0;
  int op;
  printf("Selecione o tipo de funcao:\n1 - Arcoseno\n2 - Arcocosseno\n3 - Arcotangente\n4 - Arcosecante\n5 - Arcocossecante\n6 - Arcocotangente\n");
  scanf("%d",&op);
  if(a == b){
     return p;
 }
 a = mathToRadians(a);
 b = mathToRadians(b);
 while(a <= b){
   if (op == 1) {
     soma = n*(pow(asin(a),grau));
   } else if (op == 2) {
     soma = n*(pow(acos(a),grau));
   }else if(op ==3){
     soma = n*(pow(atan(a),grau));
   }else if(op == 4){
     soma = n*(pow((1/acos(a)),grau));
   }else if (op == 5) {
     soma = n*(pow((1/asin(a)),grau));
   }else if (op == 6) {
     soma = n*(pow((1/atan(a)),grau));
   }
     a = a + n;
     p = p + soma;
 }
 return p;
}

double integralTrigonometricaHiperbolica(double b,double a, double n, double grau){
  double soma = 0.0,p = 0.0;
  int op;
  printf("Selecione o tipo de funcao:\n1 - seno Hiperbolico\n2 - cosseno Hiperbolico\n3 -tangente Hiperbolica\n4 - secante Hiperbolica\n5 - cossecante Hiperbolica\n6 - cotangente Hiperbolica\n");
  scanf("%d",&op);
  if(a == b){
     return p;
 }
 a = mathToRadians(a);
 b = mathToRadians(b);
 while(a <= b){
   if (op == 1) {
     soma = n*(pow(sinh(a),grau));
   } else if (op == 2) {
     soma = n*(pow(cosh(a),grau));
   }else if(op ==3){
     soma = n*(pow(tanh(a),grau));
   }else if(op == 4){
     soma = n*(pow((1/cosh(a)),grau));
   }else if (op == 5) {
     soma = n*(pow((1/sinh(a)),grau));
   }else if (op == 6) {
     soma = n*(pow((1/tanh(a)),grau));
   }
     a = a + n;
     p = p + soma;
 }
 return p;
}

double integralTrigonometricaHiperbolicaInversa(double b,double a, double n, double grau){
  double soma = 0.0,p = 0.0;
  int op;
  printf("Selecione o tipo de funcao:\n1 - Arcoseno Hiperbolico\n2 - Arcocosseno Hiperbolico\n3 -Arcotangente Hiperbolica\n4 - Arcosecante Hiperbolica\n5 - Arcocossecante Hiperbolica\n6 - Arcocotangente Hiperbolica\n");
  scanf("%d",&op);
  if(a == b){
     return p;
 }
 a = mathToRadians(a);
 b = mathToRadians(b);
 while(a <= b){
   if (op == 1) {
     soma = n*(pow(asinh(a),grau));
   } else if (op == 2) {
     soma = n*(pow(acosh(a),grau));
   }else if(op ==3){
     soma = n*(pow(atanh(a),grau));
   }else if(op == 4){
     soma = n*(pow((1/acosh(a)),grau));
   }else if (op == 5) {
     soma = n*(pow((1/asinh(a)),grau));
   }else if (op == 6) {
     soma = n*(pow((1/atanh(a)),grau));
   }
     a = a + n;
     p = p + soma;
 }
 return p;
}


double mathToRadians(double a){
  return a*(M_PI/180);
}
