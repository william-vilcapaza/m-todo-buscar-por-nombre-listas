#include <iostream>
using namespace std;

class Persona
{
    //atributos
    string dni;
    string nombre;
    string celular;
    string telefono;
    string direccion;
    string correo;

public:
    //constructor
    Persona() {}
    //Metodos - setters and getters
    void setDni(string valor)
    {
        dni = valor;
    }
    void setNombre(string valor)
    {
        nombre = valor;
    }
    void setCelular(string valor)
    {
        celular = valor;
    }
    void setTelefono(string valor)
    {
        telefono = valor;
    }
    void setDireccion(string valor)
    {
        direccion = valor;
    }
    void setCorreo(string valor)
    {
        correo = valor;
    }
    string getDni()
    {
        return dni;
    }
    string getNombre()
    {
        return nombre;
    }
    string getCelular()
    {
        return celular;
    }
    string getTelefono()
    {
        return telefono;
    }
    string getDireccion()
    {
        return direccion;
    }
    string getCorreo()
    {
        return correo;
    }
};


class Nodo {
    //Atributos
    Persona dato; //char, float, string, objeto
    Nodo* enlace;//puntero..
public:
    //Constructor - inicializar los atributos
    Nodo(Persona dato)
    {
        this->dato = dato;
        enlace = NULL;//por que no apuntamos a ningun nodo
    }
    //getter and setter
    Persona getDato()
    {
        return dato;
    }
    void setDato(Persona dato)
    {
        this->dato = dato;
    }
    Nodo* getEnlace()
    {
        return this->enlace;
    }
    void setEnlace(Nodo* enlace)
    {
        this->enlace = enlace;
    }
    void imprimir()
    {
        cout << "/-------------------\\" << endl;
        cout << "|DNI: " << dato.getDni() << endl;
        cout << "|Nombre: " << dato.getNombre() << endl;
        cout << "|Celular: " << dato.getCelular() << endl;
        cout << "|Telefono: " << dato.getTelefono() << endl;
        cout << "|Direccion: " << dato.getDireccion() << endl;
        cout << "|Correo: " << dato.getCorreo() << endl;
        cout << "|-------------------" << endl;
        cout << "|Enlace: " << enlace << endl;
        cout << "\\------------------/" << endl;
    }
};

class Lista {
    Nodo* inicio;
public:
    Lista()
    {
        this->inicio = NULL;
    }
    void InsertarAlFinal(Persona dato)
    {
        Nodo* temp = new Nodo(dato);
        if (EstaVacia())//lista vacia
        {
            inicio = temp;
        }
        else
        {
            Nodo* recorrido = this->inicio;
            while (recorrido->getEnlace() != NULL)
            {
                recorrido = recorrido->getEnlace();
            }
            recorrido->setEnlace(temp);
        }
    }
    void InsertarAlInicio(Persona dato)
    {
        Nodo* temp = new Nodo(dato);
        if (EstaVacia())//lista vacia
        {
            inicio = temp;
        }
        else
        {
            Nodo* recorrido = this->inicio;
            this->inicio = temp;
            this->inicio->setEnlace(recorrido);
        }
    }
    void Imprimir()
    {
        int i = 1;
        Nodo* recorrido = inicio;
        cout << "Lista enlazada****************************" << endl;
        while (recorrido != NULL)
        {
            cout << "---> Nodo " << i++ << endl;
            recorrido->imprimir();
            recorrido = recorrido->getEnlace();
        }
        cout << "****************************" << endl << endl;
    }
    void Buscar(string dni)
    {
        bool encontrado = false;
        Nodo* recorrido = inicio;
        while (recorrido != NULL)
        {
            if (recorrido->getDato().getDni() == dni)
            {
                recorrido->imprimir();
                encontrado = true;
                break;
            }
            else
            {
                recorrido = recorrido->getEnlace();
            }
        }
        if (encontrado == false)
        {
            cout << "El elemento buscado no fue encontrado." << endl;
        }
    }
    void BuscarNombre(string nombre)
    {
        bool encontrado = false;
        Nodo* recorrido = inicio;
        while (recorrido != NULL)
        {
            if (recorrido->getDato().getNombre() == nombre)
            {
                recorrido->imprimir();
                encontrado = true;
                break;
            }
            else
            {
                recorrido = recorrido->getEnlace();
            }
        }
        if (encontrado == false)
        {
            cout << "El elemento buscado no fue encontrado.\n" << endl;
        }
    }
    void EliminarElementoFinal()
    {
        if (EstaVacia())
        {
            cout << "No hay elemento a eliminar" << endl;
        }
        else
        {
            if (inicio->getEnlace() == NULL)
            {
                inicio = NULL;
            }
            else
            {
                Nodo* recorrido = inicio;
                while (recorrido->getEnlace() != NULL)
                {
                    //cout<<recorrido->getDato()<<"\t";
                    if (recorrido->getEnlace()->getEnlace() != NULL)
                        recorrido = recorrido->getEnlace();
                    else
                        break;
                }
                cout << endl;
                //recorrido->imprimir();
                recorrido->setEnlace(NULL);
                //recorrido->imprimir();
            }

        }

    }
    void EliminarElementoEnPosicion(int posicion)
    {
        int contador = 0;
        if (EstaVacia())
        {
            cout << "No hay elemento a eliminar" << endl;
        }
        else
        {
            if (posicion == 0)
            {
                EliminarElementoInicio();
            }
            else
            {
                Nodo* recorrido = inicio;

                while (recorrido->getEnlace() != NULL)
                {
                    if (contador == posicion - 1)
                    {
                        recorrido->setEnlace(recorrido->getEnlace()->getEnlace());
                        break;
                    }
                    else
                    {
                        contador++;
                        recorrido = recorrido->getEnlace();
                    }

                }
            }


        }
    }
    void EliminarElementoInicio()
    {
        if (EstaVacia())
        {
            cout << "No hay elemento a eliminar" << endl;
        }
        else
        {
            inicio = inicio->getEnlace();
        }
    }
    void Vaciar()
    {
        inicio = NULL;
    }
    bool EstaVacia()
    {
        if (inicio == NULL)
            return true;
        else
            return false;
    }

};

void MostrarMenu()
{
    cout << "1.- Ver el contenido de la lista enlazada" << endl;
    cout << "2.- Insertar un elemento al inicio" << endl;
    cout << "3.- Insertar un elemento al final" << endl;
    cout << "4.- Buscar un elemento" << endl;
    cout << "5.- Eliminar un elemento inicial" << endl;
    cout << "6.- Eliminar un elemento final" << endl;
    cout << "7.- Vaciar la lista" << endl;
    cout << "8.- Eliminar un elemento en la posición" << endl;
    cout << "9.- Buscar un elemento por nombre" << endl;
    cout << "0.- Salir" << endl;
}
Persona LeerDatosPersona()
{
    Persona persona = Persona();
    string temporal;

    cout << "Ingrese DNI: " << endl;
    cin >> temporal;
    persona.setDni(temporal);

    cout << "Ingrese Nombre: " << endl;
    cin >> temporal;
    persona.setNombre(temporal);

    cout << "Ingrese Celular: " << endl;
    cin >> temporal;
    persona.setCelular(temporal);

    cout << "Ingrese Telefono: " << endl;
    cin >> temporal;
    persona.setTelefono(temporal);

    cout << "Ingrese Direccion: " << endl;
    cin >> temporal;
    persona.setDireccion(temporal);

    cout << "Ingrese Correo: " << endl;
    cin >> temporal;
    persona.setCorreo(temporal);

    return persona;
}

int main()
{
    Lista agenda = Lista();
    int posicion;
    string dni;
    string nombre;
    Persona elemento = Persona();
    int opcion;
    do
    {
        MostrarMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 0:
            cout << "Ingeniería de Sistemas, hasta luego." << endl;
            break;
        case 1:
            agenda.Imprimir();
            break;
        case 2:
            agenda.InsertarAlInicio(LeerDatosPersona());
            break;
        case 3:
            agenda.InsertarAlFinal(LeerDatosPersona());
            break;
        case 4:
            cout << "Digite el numero de dni: " << endl;
            cin >> dni;
            agenda.Buscar(dni);
            break;
        case 5:
            agenda.EliminarElementoInicio();
            break;
        case 6:
            agenda.EliminarElementoFinal();
            break;
        case 7:
            agenda.Vaciar();
            break;
        case 8:
            cout << "Digite posición: " << endl;
            cin >> posicion;
            agenda.EliminarElementoEnPosicion(posicion);
            break;
        case 9:
            cout << "Digite el nombre: " << endl;
            cin >> nombre;
            agenda.BuscarNombre(nombre);
            break;

        default:
            cout << "Opción no valida." << endl;
            break;
        }
    } while (opcion != 0);

}
