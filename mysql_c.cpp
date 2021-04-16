
#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;
int main()
{

    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "Empres123", "db_productos", 3306, NULL, 0);
    if (conectar) {
        //cout << "conexion exitosa..." << endl;
         string Marcas;
        cout << "ingrese marca: ";
        cin >> Marcas;

        string insert = "insert into marcas(Marcas) values('" + Marcas + "')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado) {
            cout << "ingreso exitosa..." << endl;
        }
        else {
            cout << "XXX Error al ingresar XXXX " << endl;
        }

    }
    else {
        cout << "error en la conexion..." << endl;
    }

        string consulta = "select *from Marcas";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)){
                cout << fila[0] << "," << fila[1] << endl;

            }

        }
        else {
            cout << "Ingreso error..." << endl;

            system("pause");
            return 0;



        }

    }