
#include <iostream>
#include "tree.hpp"
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

// Funcion para remover todas las ocurrencias en un vector
template <typename T>
void removal(std::vector<T> &v, T &target)
{
    v.erase(std::remove(v.begin(), v.end(), target), v.end());
}

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string tok;
    
    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
    string target = "";
    removal(internal, target);
    return internal;
}


int main(int nargs, char** vargs){

	
    cout << "¡Bienvenido a treeSO!" << endl;
    cout << "Autores: 「 Tomas Poch 」 y 「 Rodrigo Vildosola 」" << endl << endl;

    Tree tree;
    TreeNode* curr_dir = tree.setRoot(new TreeNode("/"));
    while (1) {
        cout << tree.path(curr_dir->getData()) << " > ";
        string comando;
        getline(cin, comando);
        vector<string> args = split(comando, ' ');

        if (args[0] == "cd") {
            if (args.size() == 1) {
                curr_dir = tree.find("/");
            }
            else if (args[1] == "..") {
                if (curr_dir->getData() == "/") {
                    cout << "No se puede retroceder más" << endl;
                }
                else {
                    curr_dir = curr_dir->getParent();
                }
            }
            else {
                TreeNode* new_dir = tree.find_child(args[1], curr_dir);
                if (new_dir == nullptr) {
                    cout << "No existe el directorio" << endl;
                }
                else if (new_dir->getIsFolder() == 0) {
                    cout << "No es un directorio" << endl;
                }
                else {
                    curr_dir = new_dir;
                }
            }
        }

        else if (args[0] == "mkdir") {
            if (args.size() == 1) {
                cout << "No se ha ingresado un nombre de directorio" << endl;
            }
            else if (tree.find(args[1]) != nullptr) {
                cout << "Ya existe un archivo con ese nombre" << endl;
            }
            else {
                tree.insert(args[1], curr_dir->getData(), 1);
            }

        }

        else if (args[0] == "mkfile") {
            if (args.size() <= 2) {
                cout << "No se ha ingresado un nombre de archivo" << endl;
            }
            else if (tree.find(args[2]) != nullptr) {
                cout << "Ya existe un archivo con ese nombre" << endl;
            }
            else {
                vector<string> dirs = split(args[1], '/');
                string file_name = dirs[dirs.size() - 1];
                if (tree.path(file_name) == args[1]) {
                    tree.insert(args[2], file_name, 0);
                }
                else {
                    cout << "Camino no existe" << endl;
                }
            }
        }

        else if (args[0] == "ls") {
            if (args.size() == 1) {
                tree.print(curr_dir);
            }
            else {
                cout << "Opción no válida" << endl;
            }
        }

        else if (args[0] == "rm") {
            if (args.size() == 1) {
                cout << "No se ha ingresado un nombre de archivo o directorio" << endl;
            }
            else {
                TreeNode* node = tree.find_child(args[1], curr_dir);
                if (node == nullptr) {
                    cout << "No existe el archivo o directorio" << endl;
                }
                else if (node == curr_dir) {
                    cout << "No se puede eliminar el directorio actual" << endl;
                }
                else {
                    tree.remove(node);
                }
            }
        }

        else if (args[0] == "tree") {
            if (args.size() == 1) {
                tree.traverse();
            }
            else {
                cout << "Opcion no valida" << endl;
            }
        }

        else if (args[0] == "find") {
            if (args.size() <= 2) {
                cout << "No se ha ingresado un nombre de archivo" << endl;
            }

            else {
                vector<string> dirs = split(args[1], '/');
                string file_name = dirs[dirs.size() - 1];
                TreeNode* node = tree.find(file_name);
                if (node != nullptr && tree.find_curr(args[2], node) != nullptr) {
                    string path = tree.find_curr(args[2], node)->getData();
                    cout << "Path: " << tree.path(path) << endl;

                }
                else {
                    cout << "No existe el archivo" << endl;
                }
            }
        }

        else if (args[0] == "exit") {
            goto end;
        }

        else {
            cout << "Comando no reconocido" << endl;
        }
    }

    end:
    cout << "program terminated" << endl;
	return 0;
}
