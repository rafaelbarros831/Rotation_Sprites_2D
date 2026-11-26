#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <string>

int GameState = 1, personagem;
std::string endereco;

float scalX, scalY;

class Movilet {
public:

	float posiX = 50.0f, posiY = 200.0f;

	void MovimentoSv() {

		if (posiY >= 150.0f && posiY < 170.0f) posiY += 0.2f;
		if (posiY >= 170.0f) posiY = 150.0f;

	}

};

void carrega_Textura(int escl) {

	if (escl == 1) {
		endereco = "Sprites/Pirata_001.png";
		scalX = 1.4f;
		scalY = 1.4f;
	}
	else if (escl == 2) {
		endereco = "Sprites/Mario.png";
		scalX = 0.2f;
		scalY = 0.2f;
	}

	else if (escl == 3) {
		endereco = "Sprites/Pirata_002.png";
		scalX = 1.4f;
		scalY = 1.4f;
	}

	else if (escl == 4) {
		endereco = "Sprites/mulher_pirata01.png";
		scalX = 2.0f;
		scalY = 2.0f;
	}

	else if (escl == 5) {
		endereco = "Sprites/Link.png";
		scalX = 0.3f;
		scalY = 0.3f;
	}

	else if (escl == 6) {
		endereco = "Sprites/mulher_pirata02.png";
		scalX = 2.0f;
		scalY = 2.0f;
	}

}

int main() {

	printf("\nEscolha um numero de 1 a 6 para selecionar um personagem...\n");
	printf("Digite sua escolha:");
	scanf_s("%d", &personagem);

	carrega_Textura(personagem);


	sf::Texture tx_background("Sprites/Fundo.jpg");
	sf::Sprite background(tx_background);
	background.setPosition(sf::Vector2f(0.0f, 0.0f));

	sf::Texture tx_letreiro("Sprites/Letprt.png");
	sf::Sprite letreiro(tx_letreiro);

	sf::Texture tx_sprite(endereco);
	sf::Sprite Sprite(tx_sprite);
	Sprite.setPosition(sf::Vector2f(300.0f, 300.0f));
	Sprite.setScale(sf::Vector2f(scalX, scalY));

	sf::FloatRect Center = Sprite.getLocalBounds();
	Sprite.setOrigin(sf::Vector2f(Center.size.x / 2.0f, Center.size.y / 2.0f));
	sf::RenderWindow janela(sf::VideoMode({600, 600}), "Janela");
	
	printf("\nPresione ENTER na tela de titulo para comecar...");

	janela.setFramerateLimit(60);

	Movilet leter;


	while (janela.isOpen() == true) {

		if (GameState == 1) {

			while (std::optional evento = janela.pollEvent()) {

				if (evento->is<sf::Event::Closed>()) {
					janela.close();
				}

			}

			janela.clear(sf::Color::Cyan);

			leter.MovimentoSv();
			letreiro.setPosition(sf::Vector2f(leter.posiX, leter.posiY));

			janela.draw(letreiro);
			janela.display();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
				GameState = 2;
			}
		}

			if (GameState == 2) {


				while (std::optional evento = janela.pollEvent()) {

					if (evento->is<sf::Event::Closed>()) {
						janela.close();
					}

				}


				janela.clear();
				janela.draw(background);


				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
					Sprite.setRotation(sf::degrees(-90.0f));
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
					Sprite.setRotation(sf::degrees(-180.0f));
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
					Sprite.setRotation(sf::degrees(-270.0f));
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F)) {
					Sprite.setRotation(sf::degrees(-360.0f));
				}

				sf::Vector2f CalPosi = Sprite.getTransform().transformPoint(sf::Vector2f(0.0f, 0.0f));

				printf("X = %.2f, Y = %.2f, Angulo: %f graus\n", CalPosi.x, CalPosi.y, Sprite.getRotation().asDegrees());

				janela.draw(Sprite);
				janela.display();
			}
	}

return 0;
}