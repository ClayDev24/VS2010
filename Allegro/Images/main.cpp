#include <allegro5/allegro.h>       // Inclui o cabe�alho da bibilioteca Allegro 5
#include <allegro5/allegro_image.h> // Inclui o cabe�alho do add-on para uso de imagens
#include <allegro5/allegro_native_dialog.h> // Caixas de texto
#include <stdio.h> // printf
#include <conio.h> // getche()
 
int main(void) {
    // Vari�vel representando a janela principal
    ALLEGRO_DISPLAY *janela = NULL;
    // Vari�vel representando a imagem
    ALLEGRO_BITMAP  *imagem = NULL;
    // Inicializa a Allegro
    al_init();
    // Inicializa o add-on para utiliza��o de imagens
    al_init_image_addon();
    // Configura a janela
    janela = al_create_display(640, 480);
    // Carrega a imagem
    imagem = al_load_bitmap("I:\\Progra~2\\C++\\Visual~1\\Allegro\\Debug\\anglepie1.bmp");
    // Desenha a imagem na tela
    al_draw_bitmap(imagem, 50, 50, 0);

	//al_draw_rotated_bitmap(imagem, 50, 50, 60, 60, 45, 0);
	//al_draw_scaled_bitmap();
	//al_draw_scaled_rotated_bitmap();
	int width = al_get_bitmap_width(imagem);
	int height = al_get_bitmap_height(imagem);

    // Atualiza a tela
    al_flip_display();
    // Segura a execu��o por 5 segundos
    al_rest(5.0);
    // Finaliza a janela
    al_destroy_display(janela);

	//<<_CAIXAS DE TEXTO_>>
	//guarda o t�tulo da caixa de texto
    char *tcaixa = "Meu titulo";
    //o t�tulo da mensagem dentro da caixa
    char *titulo = "Sou uma caixa de texto";
    //o conte�do da mensagem exibida
    char *texto = "A mensagem a ser exibida deve ficar aqui";
    //mostra a caixa de texto
    int r = al_show_native_message_box(NULL,tcaixa,titulo,texto,NULL,ALLEGRO_MESSAGEBOX_OK_CANCEL); // 1=>OK, 0=CANCEL
    printf("%i",r);
    printf("%i",width);
    printf("%i",height);

	system("pause");
    return(0);
}