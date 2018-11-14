#include <stdio.h>
#include <GL/freeglut.h>


float spin = 0;

void Spin(int value){
    spin += 1.0f;
    if (spin >= 20.0f){
        spin += 0.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(40,Timer, 1);
}


int init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);     //define a cor de fundo
    glEnable(GL_DEPTH_TEST);           //remoção de superficie oculta

    glMatrixMode(GL_PROJECTION);          //define que a matriz eh a de projeção
    glLoadIdentity();                     //carrega a matriz de identidade
     glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 50); //define uma projeção ortografica     
}

void display(){
    //limpa o buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    desenha_buleCSE(); // bule azul claro
    desenha_buleCSD(); // bule amarelo
    desenha_buleCIE(); // bule roxo
    desenha_buleCID(); // bule verde
    
    glFlush();
}

void desenha_buleCSE(){
    glColor3f(0, 1, 1);
    glPushMatrix(); //armazena a matriz corrente
        glTranslatef(-1.5, 1.5, 0);
       gluLookAt(0.0, 50.0, 1.0, 
                 0.0, 0.0, 0.0, 
                 0.0, 1.0, 0.0);
        // glRotatef(-2,2,-2,2);
        glutWireTeapot(1);
    glPopMatrix(); //restaura a matriz anterior
    
}

void desenha_buleCSD(){
    glColor3f(1, 1, 0); 
    glPushMatrix(); //armazena a matriz corrente
        glTranslatef(1.5, 1.5, 0);
        gluLookAt(-1.0, 0.0, 0.0, 
                  0.0, 0.0, 0.0, 
                  0.0, 1.0, 0.0); //camera olhando de frente
        // glRotatef(-2,2,-2,2);
        glutWireTeapot(1);
    glPopMatrix(); //restaura a matriz anterior
}


void desenha_buleCIE(){
    glColor3f(1, 0, 1);
    glPushMatrix(); //armazena a matriz corrente
        glTranslatef(-1.5, -1.5, 0);
        gluLookAt(0.0, 0.0, 1.0, 
                  0.0, 0.0, 0.0, 
                  0.0, 1.0, 0.0); //camera olhando de frente
        // glRotatef(-3,3,-3,3);
        glutWireTeapot(1);
    glPopMatrix(); //restaura a matriz anterior
}

void desenha_buleCID(){
    glColor3f(0, 1, 0);
    glPushMatrix(); //armazena a matriz corrente
        
        glTranslatef(1.5, -1.5, 0);
        glRotatef(2*spin, 1.0, 0.0, 0.0);
        gluLookAt(-1.0, 0.0, 0.0, 
                  0.0, 0.0, 0.0, 
                  0.0, 1.0, 0.0); //camera olhando de frente
        glutWireTeapot(1);
    glPopMatrix(); //restaura a matriz anterior
}


int main(int argc, char** argv){
    glutInit(&argc,argv);                           //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    //configura o modo de display
    // glutInitWindowPosition(200,0);                  //seta a posição inicial da janela
    glutInitWindowSize(800,800);                    //configura a largura e altura da janela de exibição
    glutCreateWindow("Bonus 2");                 //cria a janela de exibiçao

    init();                                         //executa função de inicializaçao
    glutDisplayFunc(display);

    glutTimerFunc(20, Spin, 1);

    glutMainLoop();                                  //mostre tudo e espere
    return 0;
}
