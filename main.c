#include <stdio.h>
#include <GL/freeglut.h>

int flag = 0;
float alpha_bule = 0.0f, alpha_bule2=0.0f;

int init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);     //define a cor de fundo
    glEnable(GL_DEPTH_TEST);           //remo��o de superf�cie oculta

    glMatrixMode(GL_PROJECTION);          //define que a matriz � a de proje��o
    glLoadIdentity();                     //carrega a matriz de identidade
    glOrtho(-5,5,-5,5,-5,5);          //define uma proje��o ortogr�fica
}

void display(void){
    //limpa o buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    desenha_bule2();
    desenha_bule();
    glFlush();
}

void desenha_bule(){

    glColor3f(1, 1, 0);
    glPushMatrix(); //armazena a matriz corrente
        glTranslatef(2, 0, 0);
        glRotatef(alpha_bule,1,0,1);
        glutWireTeapot(1.5);
    glPopMatrix(); //restaura a matriz anterior
}

void desenha_bule2(){
    glColor3f(0, 1, 1);
    glPushMatrix(); //armazena a matriz corrente
        glTranslatef(-3, 0, 0);
        glRotatef(alpha_bule,1,1,1);
        glutWireTeapot(2);
    glPopMatrix(); //restaura a matriz anterior
}

void keyPressed_special(int key, int x, int y){
    if(flag == 1){
        if(key == GLUT_KEY_RIGHT){
            alpha_bule2 += 0.5f;
        } else if(key == GLUT_KEY_LEFT){
            alpha_bule2 -= 0.5f;
        }

    } else if (flag == 2){
        if(key == GLUT_KEY_RIGHT){
            alpha_bule += 0.5f;
        } else if(key == GLUT_KEY_LEFT){
            alpha_bule -= 0.5f;
        }
    }
    glutPostRedisplay();
}

void keyboard (unsigned char key, int x, int y){
     if(key == '1'){
         flag = 1; //bule2
     } else if (key == '2'){
         flag = 2; //bule
     }
}

int main(int argc, char** argv){
    glutInit(&argc,argv);                           //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    //configura o modo de display
    glutInitWindowPosition(200,0);                  //seta a posi��o inicial da janela
    glutInitWindowSize(400,400);                    //configura a largura e altura da janela de exibi��o
    glutCreateWindow("Bonus 2");                 //cria a janela de exibi��o

    init();                                         //executa fun��o de inicializa��o
    glutKeyboardFunc(keyboard); // Registra a funcao de callback do teclado
    glutSpecialFunc(keyPressed_special);
    glutDisplayFunc(display);
    glutMainLoop();                                  //mostre tudo e espere
    return 0;
}
