#ifndef ARBOLRN_H
#define ARBOLRN_H

#include <cstdlib>
#include <iostream>
#include "./pila.h"
using namespace std;

template<class T, class S>
struct NODO{ 
  T clave;
  S info; //ingresar info
  NODO<T,S> *izq, *der;
  bool color = false; // negro = 1 true, rojo = 0 false
};

template<class T, class S>
class ARBOL{

    Pila<S> pila;
    NODO<T,S> *raiz ;
    public:	
    ARBOL() {
        raiz = NULL;
        pila = Pila<S>();
    }
    NODO<T,S> *raiz_arbol() {
        return raiz;
    }

    int ins_arbol(T,S); //modificar
    NODO<T,S> *buscarPadreNuevo(T, NODO<T,S> *, NODO<T,S> *);
    NODO<T,S> *buscarPadreExistente(T, NODO<T,S> *, NODO<T,S> *);
    void  ajusteInsercion(NODO<T,S> *);
    void  ajusteEliminacion(NODO<T,S> *);
    void borrar_NODO(NODO<T,S> *, NODO<T,S> *); //modificar
	  NODO<T,S> *buscar(T, NODO<T,S> **, NODO<T,S> *);
    int retira_arbol(T);
    NODO<T,S> *rotacionSecillaIzq(NODO<T,S> *P);
    NODO<T,S> *rotacionSecillaDer(NODO<T,S> *P);
    NODO<T,S> *rotacionDobleIzq(NODO<T,S> *P);
    NODO<T,S> *rotacionDobleDer(NODO<T,S> *P);
    S *buscarNodo(T);
    NODO<T,S> *buscarNodo2(T);
    Pila<S> *obtenerPila(NODO<T,S> *p);
    void inorden(NODO<T,S> *);
    void preorden(NODO<T,S> *);
    void posorden(NODO<T,S> *);
    void destruir(NODO<T,S> *p);
    //~ARBOL();
};

template<class T, class S>
NODO<T,S> *ARBOL<T, S>::buscarNodo2(T n){
  NODO<T,S> *q, *p=raiz;
  if(n == raiz->clave)
    return raiz;
  q=buscar(n,&p,NULL); 
  if(q->izq->clave == n)
    return q->izq;
  else
    return q->der;
}

template<class T, class S>
NODO<T,S> *ARBOL<T, S>::buscarPadreNuevo(T n, NODO<T,S> *p, NODO<T,S> *q){
  if (p -> clave == -3) 
    return q;
  if (n < p->clave){
    q=p;
    q=buscarPadreNuevo(n,p->izq,q);
    return q;
  }
  else if (n > p->clave){
    q=p;
    q=buscarPadreNuevo(n,p->der,q);
    return q;
  }
  else return NULL;
}
template<class T, class S>
NODO<T,S> *ARBOL<T, S>::buscarPadreExistente(T n, NODO<T,S> *p, NODO<T,S> *q){
  if (p -> clave == n)
    return q;
  if (n < p->clave){
    q=p;
    q=buscarPadreExistente(n,p->izq,q);
    return q;
  }
  if (n > p->clave){
    q=p;
    q=buscarPadreExistente(n,p->der,q);
    return q;
  }
  else return q;
  //else return NULL;
}

template<class T, class S>
void ARBOL<T, S> :: ajusteInsercion(NODO<T,S> *x){ 
  while(x!=raiz && buscarPadreExistente(x->clave, raiz, NULL) -> color == false){
    NODO<T,S> *padre = buscarPadreExistente(x->clave,raiz,NULL); 
    NODO<T,S> *abuelo = buscarPadreExistente(padre -> clave,raiz,NULL); 
    NODO<T,S> *tio = new NODO<T,S>;
    if(padre == abuelo -> izq){
      tio = abuelo -> der;
      //caso 1 
      if(tio -> color == false){
        padre -> color = true;
        tio -> color = true;
        abuelo -> color = false;
        x = abuelo;
      } else{
        if(x == padre -> der){ //caso 2
          x = padre;
          rotacionSecillaIzq(x);
          abuelo = buscarPadreExistente(x -> clave, raiz, NULL);
        }
        padre -> color = true;
        abuelo -> color = false;
        rotacionSecillaDer(abuelo); 
      }
    } else{
      tio = abuelo -> izq;
      if(tio -> color == false){
        padre -> color = true;
        tio -> color = true;
        abuelo -> color = false;
        x = abuelo;
      } else{
        if(x == padre -> izq){ //caso 2
          x = padre;
          rotacionSecillaDer(x); //x padre abuelo => padre abuelo bisabuelo
          padre = buscarPadreExistente(x -> clave, raiz, NULL);
          abuelo = buscarPadreExistente(padre -> clave, raiz, NULL);
        }
        padre -> color = true;
        abuelo -> color = false;
        rotacionSecillaIzq(abuelo); 
      }
    }
  } 
  raiz -> color = true;
}

template<class T, class S>
NODO<T,S> *ARBOL<T, S> :: rotacionDobleDer(NODO<T,S> *p){
 p->izq = rotacionSecillaIzq(p -> izq); 
 return rotacionSecillaDer(p); 
}
//-------------------------
template<class T, class S>
NODO<T,S> *ARBOL<T, S> :: rotacionDobleIzq(NODO<T,S> *p){
 p->der = rotacionSecillaDer(p -> der); 
 return rotacionSecillaIzq(p); 
}

template<class T, class S>
NODO<T,S> *ARBOL<T, S> :: rotacionSecillaIzq(NODO<T,S> *p){
  NODO<T,S> *q = p -> der, *bisAb = new NODO<T,S>;   
  if(p!=raiz)
    bisAb = buscarPadreExistente(p -> clave, raiz, NULL);
  else
    raiz = q;
  p -> der = q -> izq; 
  q -> izq = p;
  if(q != raiz){ 
    if(bisAb -> der == p)
      bisAb -> der = q; 
    else
      bisAb -> izq = q; 
  }
  return q;
}

template<class T, class S>
NODO<T,S> *ARBOL<T, S> :: rotacionSecillaDer(NODO<T,S> *p){
  NODO<T,S> *q = p -> izq, *bisAb = new NODO<T,S>;   
  if(p!=raiz)
    bisAb = buscarPadreExistente(p -> clave, raiz, NULL);  
  else
    raiz = q;
  p -> izq = q -> der; 
  q -> der = p;
  if(q != raiz){ 
    if(bisAb -> der == p)
      bisAb -> der = q; 
    else
      bisAb -> izq = q; 
  }
  return q;
}
//-------------------------
template<class T, class S>
int ARBOL<T, S>::ins_arbol(T n, S info){
  NODO<T,S> *q, *nulo1 = new NODO<T,S>, *nulo2 = new NODO<T,S>; 
  nulo1 -> clave = -3;
  nulo2 -> clave = -3;
  nulo1 -> color = true;
  nulo2 -> color = true;
  if (raiz == NULL){
    raiz= new NODO<T,S>;
    raiz->clave =n;
    raiz->info = info;
    raiz -> color = true;
    raiz->izq= nulo1;
    raiz->der= nulo2; //nulo
    return 0;
  } //nice
  q = buscarPadreNuevo(n,raiz,NULL); //se obtiene donde va a insertar
  //cout<<q -> clave<<endl;
  if (q==NULL) 
   return (-1);
  NODO<T,S> *nuevo;
  nuevo= new NODO<T,S>;
  nuevo->clave = n;
  nuevo->info = info;
  nuevo->izq= nulo1;
  nuevo->der= nulo2; //nulo
  if (n<q->clave)
    q->izq=nuevo;
  else   
    q->der=nuevo;
  ajusteInsercion(nuevo); //se realiza el ajuste al insertar
  return 0;
}

template<class T, class S>
void  ARBOL<T, S> :: ajusteEliminacion(NODO<T,S> *x){
  while(x!=raiz && x -> color == true){
    NODO<T,S> *padre = buscarPadreExistente(x->clave,raiz,NULL); 
    NODO<T,S> *w = new NODO<T,S>;
    if(x == padre -> izq){
      w = padre -> der;
      if(w -> color == false){
        //caso 1
        w -> color = true;
        padre -> color = false;
        rotacionSecillaIzq(padre);
        w = padre -> der;
      }
      if(w -> der -> color == true && w -> izq -> color == true){
        //caso 2
        w -> color = false;
        x = padre;
      } else{
        if( w -> der -> color == true ){
          //caso 3
          w -> izq -> color = true;
          w -> color = false;
          rotacionSecillaDer(w);
          w = padre -> der;
        }
        //caso 4
        w -> color = padre -> color;
        padre -> color = true;
        w -> der -> color = true;
        rotacionSecillaIzq(padre);
        x = raiz; 
      }
    } else{
      w = padre -> izq;
      if(w -> color == false){
        //caso 1
        w -> color = true;
        padre -> color = false;
        rotacionSecillaDer(padre);
        w = padre -> izq;
      }
      if(w -> izq -> color == true && w -> der -> color == true){
        //caso 2
        w -> color = false;
        x = padre;
      } else{
        if( w -> izq -> color == true ){
          //caso 3
          w -> der -> color = true;
          w -> color = false;
          rotacionSecillaIzq(w);
          w = padre -> izq;
        }
        //caso 4
        w -> color = padre -> color;
        padre -> color = true;
        w -> izq -> color = true;
        rotacionSecillaDer(padre);
        x = raiz; 
      }
    } 
  }
  x -> color = true;
}

template<class T, class S>
void ARBOL<T, S>::borrar_NODO(NODO<T,S> *q, NODO<T,S> *p){ //q = padre NODO<T,S> a eliminar; p = NODO<T,S> a eliminar
  NODO<T,S>  *r, *s,*t, *aux; // r = remplazo; s = padre de reemplazo; t = s
  int respaldo = 0;
  if (p->der->clave==-3){  
    if(p -> izq -> clave == -3){
      aux = p;
      ajusteEliminacion(p);
      aux -> clave = -3;
    }//izq tena algo
    if(p -> izq -> clave != -3){
      aux = p -> izq;
      ajusteEliminacion(p -> izq);
      p -> clave = aux -> clave;
      aux -> clave = -3;    
    }
  }//nulo 
  else {
    s = p;
    r=p->der; // derecha
    t=r->izq; // izquierda de r
    while(t->clave!=-3){ //nulo
      s=r; r=t; t=t->izq; //se encuentra el r 
    }
    if (r -> der -> clave == -3){
      aux = r; //r => a12 -> aux => a12
      ajusteEliminacion(r); //r => b12
      p -> clave = aux -> clave;
      aux -> clave = -3; //limpiooooo
    }else{
      respaldo = r -> clave;
      r -> clave = r -> der -> clave;
      aux = r -> der;
      ajusteEliminacion(r->der);
      p -> clave = respaldo;
      aux -> clave = -3;
    }
  }
}

template<class T, class S>
NODO<T,S> *ARBOL<T, S>::buscar(T n, NODO<T,S> **p, NODO<T,S> *q){
	if (*p==NULL) 
    return NULL;
	if (n <(*p)->clave){
	          q=*p;
	           *p=(*p)->izq;
	          q=buscar(n,p,q);
	          return q;}
	else if (n>(*p)->clave){
		q=*p;
		*p=(*p)->der;
		q =buscar(n,p,q);
		return q;
  }
  else return q;
}

template<class T, class S>
int ARBOL<T, S>:: retira_arbol(T n){
  NODO<T,S> *q, *p=raiz;
  q=buscar(n,&p,NULL); 
  if (p==NULL) 
    return -1;
  borrar_NODO(q,p);
  return 0;
}

template<class T, class S>
void ARBOL<T, S>::inorden(NODO<T,S> *p){
if (p!=NULL){
        inorden(p->izq);
        if(p->clave != -3){
          cout<<p->clave<<" color: ";
          cout<<p->color<<endl;
        }
        inorden(p->der);
  }
}

template<class T, class S>
void ARBOL<T, S>::preorden(NODO<T,S> *p){
if (p!=NULL){
      if(p->clave != -3){
        cout<<p->clave<<" color: ";
        cout<<p->color<<endl;
      }
       preorden(p->izq);
       preorden(p->der);
  }
}

template<class T, class S>
void ARBOL<T, S>::posorden(NODO<T,S> *p){
if (p!=NULL){
       posorden(p->izq);
       posorden(p->der);
      if(p->clave != -3){
        cout<<p->clave<<" color: ";
        cout<<p->color<<endl;
      }
  }
}

template<class T, class S>
void ARBOL<T, S>::destruir(NODO<T,S> *p){
if (p!=NULL){
      destruir(p->izq);
      destruir(p->der);
      delete p;
      cout<<"NODO<T,S> destruido..."<< endl;
  }
}

template<class T, class S>
S *ARBOL<T, S>::buscarNodo(T n){
  NODO<T,S> *q, *p=raiz;
  if(n == raiz->clave)
    return &raiz->info;
  q=buscar(n,&p,NULL); 
  if(q->izq->clave == n)
    return &q->izq->info;
  else
    return &q->der->info;
}

template<class T, class S>
Pila<S> *ARBOL<T,S> :: obtenerPila(NODO<T,S> *p ){
  //NODO<T,S> p = ;
  if (p!=NULL){
          obtenerPila(p->izq);
          if(p->clave != -3){
            pila.push(p->info);
          }
          obtenerPila(p->der);
    }
  return &pila;
}
#endif
