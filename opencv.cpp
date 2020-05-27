#include "opencv.hpp"

using namespace cv;
using namespace std;

int main()
{
    // Elemento básico: matriz. imread: lê um arquivo de imagem
    Mat img = imread("wallpaper_baby_groot.jpg");

    // Matriz de 8 bits de 1 canal. De mesmo tamanho da original
    Mat imgR = Mat(img.rows, img.cols, CV_8UC1);

    // <Matriz de 8 bits de 3 canais. De mesmo tamanho da original
    Mat imgRC = Mat::zeros(img.rows, img.cols, CV_8UC3);

    // Exibir a imgem
    imshow("Imagem original", img);

    // Localizar o pixel 0,0 e Setando o pixel para zero
    img.at<Vec3b>(100, 100)[0] = 0;
    img.at<Vec3b>(100, 100)[1] = 0;
    img.at<Vec3b>(100, 100)[2] = 0;

    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            // Copiando o canal vermelho da imagem original
            imgR.at<uchar>(i, j) = img.at<Vec3b>(i, j)[2];
            imgRC.at<Vec3b>(i, j)[2] = img.at<Vec3b>(i, j)[2];
            if (i == j)
            {
                img.at<Vec3b>(i, j)[0] = 255;
                img.at<Vec3b>(i, j)[1] = 255;
                img.at<Vec3b>(i, j)[2] = 255;
            }
        }
    }
    
    imshow("Pixel Alterado", img);
    imshow("Canal Vermelho - Cinza", imgR);
    imshow("Canal Vermelho - RGB", imgRC);

    // Laço para que o programa somente se encerre ao pressionar ESC
    while (true)
    {
        // Lendo o teclado
        int c = waitKey(0);
        // Se a tecla for ESC, termine
        if (c == 27)
            break;    
    }

    return 0;
}