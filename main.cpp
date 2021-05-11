/* Implementar un template de un arreglo dinamico que cuente con los siguientes metodos:
   1. Un constructor que permita indicar la capacidad inicial del arreglo
   2. Un constructor que permita indicar la longitud y capacidad iniciales del arreglo
   3. Un constructor que permita copiar un arreglo
   4. Una sobrecarga del operador = para copiar los elementos de otro arreglo
   5. Un método para averiguar la longitud del arreglo
   6. Una sobrecarga del operador [] para acceder a una posicion del arreglo
   7. Un método para agregar un elemento al final del arreglo
   8. Un método para averiguar la posicion de un elemento en el arreglo
   9. Un método para averiguar si el vector esta vacio
*/

#include"arreglo.hpp"

int main(){
    ArregloDinamico<int> arr(5);
    arr.agregarAlFinal(1);
    arr.agregarAlFinal(2);
    arr.agregarAlFinal(3);
    arr[1] = 5;

    cout<<"Longitud del arreglo: "<<arr.longitud()<<endl;
    cout<<"Arreglo esta vacio: "<<arr.estaVacio()<<endl;

    ArregloDinamico<string> arr2(10);
    arr2.agregarAlFinal("hola");
    arr2.agregarAlFinal("mundo");
    arr2.agregarAlFinal("bien");

    cout<<"hola esta en la posicion: "<<arr2.posicionDe("hola")<<endl;
    ArregloDinamico<string> arr3(arr2);
    cout<<"bien esta en la posicion: "<<arr3.posicionDe("bien")<<endl;

    arr.agregarAlFinal(4);
    arr.agregarAlFinal(5);
    arr.agregarAlFinal(6);
    arr.agregarAlFinal(7);

    cout<<"Longitud del arreglo: "<<arr.longitud()<<endl;    

}