#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <string>

int personagem;
std::string endereco;

float scalX, scalY;

void carrega_Textura(int escl) {

	if (escl == 1) {
		endereco = "x64/Debug/Pirata_001.png";
		scalX = 2.0f;
		scalY = 2.0f;
	}
	else if (escl == 2) {
		endereco = "x64/Debug/Mario.png";
		scalX = 0.2f;
		scalY = 0.2f;
	}

}

int main() {

	printf("\nEscolha um personagem:\nSelecione 1 para PIRATA e 2 para MARIO...\n");
	printf("Digite sua escolha:");
	scanf_s("%d", &personagem);

	carrega_Textura(personagem);



	/*sf::RectangleShape quadrado(sf::Vector2f(100.0f, 100.0f));
	quadrado.setFillColor(sf::Color::Green);
	quadrado.setPosition(sf::Vector2f(300.0f, 300.0f));*/

	sf::Texture tx_sprite(endereco);
	sf::Sprite Sprite(tx_sprite);
	Sprite.setPosition(sf::Vector2f(300.0f, 300.0f));
	Sprite.setScale(sf::Vector2f(scalX, scalY));

	sf::FloatRect Center = Sprite.getLocalBounds();
	Sprite.setOrigin(sf::Vector2f(Center.size.x / 2.0f, Center.size.y / 2.0f));
	sf::RenderWindow janela(sf::VideoMode({600, 600}), "Janela");
	
	while (janela.isOpen() == true) {

		while (std::optional evento = janela.pollEvent()) {

			if (evento->is<sf::Event::Closed>()) {
				janela.close();
			}

		}


		janela.clear(sf::Color::Cyan);


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

return 0;
}