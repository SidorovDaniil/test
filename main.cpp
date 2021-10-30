#include <iostream>
#include <vector>
#include <cmath>
#include <string>

double recurs(std::vector<double> X, double n){
    if (n == 0) {
        return 0;
    }
    else {
        return 2 * X[n-1] - recurs(X, n - 1);
    }
}
//Функция, возвращающая координату Y параболы в различных точках X
std::vector<double> coords(std::vector<double> X,double vx, double vy, double h,double g,int n, std::vector<double> recX){
    std::vector<double> Y;

    for(int i = 0; i < X.size(); i++){
        double a = h + pow(-1,n)*(X[i]-recurs(recX,n))*vy/vx - pow((X[i]-recurs(recX,n)),2)*g/(2*pow(vx,2));
        Y.push_back(a);
    }
    return Y;
}

int main() {
    double vx = 10;
    double vy = 3;
    double h = 5;
    double g = 10;
    std::string way = "Right";//начальное направление движения

    int n = 0;//счетчик для рекурсии
    int n_p = 0;// Номер перегородки от которой мы отразились

    std::vector<double> Y_true;// Y координата мячика
    std::vector<double> Y_per;//Y координата перегородки
    std::vector<double> X_per;//X координата перегородки
    std::vector<double> X_rec;//X координата перегородок, от которых мячик отразися

    X_per.push_back(0.2);
    X_per.push_back(1);
    X_per.push_back(3.9);

    Y_per.push_back(1.5);
    Y_per.push_back(2.4);
    Y_per.push_back(10);


    for(int i = 0; i < X_per.size(); i++){
        std:: cout <<"coords X and Y is (" << X_per[i] << ", " << coords(X_per,vx,vy,h,g,n,X_rec)[i]<< ")" <<std::endl;
        Y_true.push_back(coords(X_per,vx,vy,h,g,n,X_rec)[i]);
    }

//Первое столкновение
    for(int i = 0; i<X_per.size(); i++){
        if(Y_true[i] < Y_per[i]){
            n_p = i;
            way = "Left";
            n++;
            X_rec.push_back(X_per[i]);
            break;
        }
    }
    std::cout << "n_p = " << n_p << " Y(n_p) = " << Y_true[n_p] << " way is " << way << "X_rec" << X_rec[n_p] << std::endl;

//    while(way == "Left"){
//        if(way == "Left"){
//            for(int i = n_p - 1; i >= 0; i--){
//                Y_true = coords(X_per,vx,vy,h,g,n,X_rec);
//                if (Y_true[i] < Y_per[i]){
//                    n_p = i;
//                    way = "Right";
//                    n++;
//                }
//            }
//        }
//    }
    return 0;
}
