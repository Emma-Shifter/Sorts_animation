#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

void bubble_sort();
void shake_sort();
void addition_sort();
void Shella_sort();
void choosing_sort();
void saming_sort();

// to - куда перемещаем
// dt - время кадра в секундах
// speed - скорость в "пикселях в секунду"
void moveTo(Transformable& obj, Vector2f to, float dt, float speed)
{
    if (obj.getPosition() != to)
    {
        Vector2f const delta = to - obj.getPosition();
        float const ds = speed * dt;
        float const off = ds / std::sqrt(delta.x * delta.x + delta.y * delta.y);
        Vector2f const pos = off < 1 ? obj.getPosition() + delta * off : to;
        obj.setPosition(pos);
    }
}

void menu(RenderWindow& window)
{
    //Графика
    Image character_image;
    character_image.loadFromFile("images/character.png");
    Texture character_texture;
    character_texture.loadFromImage(character_image);
    Sprite character_sprite;
    character_sprite.setTexture(character_texture);
    character_sprite.setPosition(500, 300);
    Image background_image;
    background_image.loadFromFile("images/background.png");
    Texture background_texture;
    background_texture.loadFromImage(background_image);
    Sprite background_sprite;
    background_sprite.setTexture(background_texture);
    background_sprite.setPosition(0, 0);
    Texture button_bubble_sort, button_shake_sort, button_addition_sort, button_Shella_sort, button_choosing_sort, button_saming_sort, button_exit;
    button_bubble_sort.loadFromFile("images/button_bubble_sort.png");
    button_shake_sort.loadFromFile("images/button_shake_sort.png");
    button_addition_sort.loadFromFile("images/button_addition_sort.png");
    button_Shella_sort.loadFromFile("images/button_Shella_sort.png");
    button_choosing_sort.loadFromFile("images/button_choosing_sort.png");
    button_saming_sort.loadFromFile("images/button_saming_sort.png"); //сортировка слиянием
    button_exit.loadFromFile("images/button_exit.png");
    Sprite bubble(button_bubble_sort), shake(button_shake_sort), addition(button_addition_sort), Shella(button_Shella_sort), choosing(button_choosing_sort), saming(button_saming_sort), exit(button_exit);
    bubble.setPosition(30, 30);
    shake.setPosition(280, 30);
    addition.setPosition(530, 30);
    Shella.setPosition(780, 30);
    choosing.setPosition(30, 160);
    saming.setPosition(280, 160); 
    exit.setPosition(30, 600);

    bool isMenu = 1;
    int menuNum = 0;

    while (isMenu)
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        menuNum = 0;

        if (IntRect(30, 30, 270, 130).contains(Mouse::getPosition(window))) { menuNum = 1; }
        if (IntRect(280, 30, 520, 130).contains(Mouse::getPosition(window))) { menuNum = 2; }
        if (IntRect(530, 30, 770, 130).contains(Mouse::getPosition(window))) { menuNum = 3; }
        if (IntRect(780, 30, 1020, 130).contains(Mouse::getPosition(window))) { menuNum = 4; }
        if (IntRect(30, 160, 270, 260).contains(Mouse::getPosition(window))) { menuNum = 5; }
        if (IntRect(280, 160, 520, 260).contains(Mouse::getPosition(window))) { menuNum = 6; }
        if (IntRect(30, 600, 270, 700).contains(Mouse::getPosition(window))) { menuNum = 7; }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) { isMenu = false; window.close(); bubble_sort(); }
            if (menuNum == 2) { isMenu = false; window.close(); shake_sort(); }
            if (menuNum == 3) { isMenu = false; window.close(); addition_sort(); }
            if (menuNum == 4) { isMenu = false; window.close(); Shella_sort(); }
            if (menuNum == 5) { isMenu = false; window.close(); choosing_sort(); }
            if (menuNum == 6) { isMenu = false; window.close(); saming_sort(); }
            if (menuNum == 7) { window.close(); isMenu = false; }
        }

        window.draw(background_sprite);
        window.draw(character_sprite);
        window.draw(bubble);
        window.draw(shake);
        window.draw(addition);
        window.draw(Shella);
        window.draw(choosing);
        window.draw(saming);
        window.draw(exit);
        window.display();

    }

}

void bubble_sort()
{
    RenderWindow window_bubble_sort(VideoMode(1070, 700), "Bubble Sort");
    window_bubble_sort.setFramerateLimit(60);

    //Графика
    Texture background_sorts_texture, button_start_texture, button_exit_texture, character_texture, text_dialog_texture;
    background_sorts_texture.loadFromFile("images/background_sorts.png");
    button_start_texture.loadFromFile("images/button_start.png");
    button_exit_texture.loadFromFile("images/button_exit.png");
    character_texture.loadFromFile("images/character.png");
    text_dialog_texture.loadFromFile("images/text_dialog.png");
    Sprite background_sorts(background_sorts_texture), button_start(button_start_texture), button_exit(button_exit_texture), character(character_texture), text_dialog(text_dialog_texture);
    background_sorts.setPosition(0, 0);
    button_start.setPosition(30, 350);
    button_exit.setPosition(300, 350);
    character.setPosition(500, 300);
    text_dialog.setPosition(100, 500);
    Texture cube_1_texture, cube_2_texture, cube_3_texture, cube_4_texture, cube_5_texture, cube_6_texture, cube_7_texture, cube_8_texture;
    cube_1_texture.loadFromFile("images/cube_1.png");
    cube_2_texture.loadFromFile("images/cube_2.png");
    cube_3_texture.loadFromFile("images/cube_3.png");
    cube_4_texture.loadFromFile("images/cube_4.png");
    cube_5_texture.loadFromFile("images/cube_5.png");
    cube_6_texture.loadFromFile("images/cube_6.png");
    cube_7_texture.loadFromFile("images/cube_7.png");
    cube_8_texture.loadFromFile("images/cube_8.png");
    Sprite cube_1(cube_1_texture), cube_2(cube_2_texture), cube_3(cube_3_texture), cube_4(cube_4_texture), cube_5(cube_5_texture), cube_6(cube_6_texture), cube_7(cube_7_texture), cube_8(cube_8_texture);
    cube_1.setPosition(550, 175);
    cube_2.setPosition(160, 175);
    cube_3.setPosition(680, 175);
    cube_4.setPosition(30, 175);
    cube_5.setPosition(940, 175);
    cube_6.setPosition(290, 175);
    cube_7.setPosition(810, 175);
    cube_8.setPosition(420, 175);

    Clock clock;
    float speed = 100.0f;
    Vector2f position = button_start.getPosition();
    int bubble_sort_num = 0;

    Font font;
    font.loadFromFile("Raleway-Regular.ttf");
    Text text("", font, 20);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);
    Text text2("", font, 20);
    text2.setFillColor(Color::Black);
    text2.setStyle(Text::Bold);
    Text text3("", font, 20);
    text3.setFillColor(Color::Black);
    text3.setStyle(Text::Bold);

    while (window_bubble_sort.isOpen())
    {
        Event event;
        while (window_bubble_sort.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window_bubble_sort.close();
        }

        bubble_sort_num = 0;
        float dt = clock.restart().asSeconds();

        if (IntRect(30, 350, 270, 450).contains(Mouse::getPosition(window_bubble_sort))) { bubble_sort_num = 1; }
        if (IntRect(300, 350, 540, 450).contains(Mouse::getPosition(window_bubble_sort))) { bubble_sort_num = 2; }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (bubble_sort_num == 1) //30, 160, 290, 420, 550, 680, 810, 940 - координаты позиций
            {
                //moveTo(cube_2, Vector2f(30, 175), dt, 50);
                //moveTo(cube_4, Vector2f(160, 175), dt, 50);
                //moveTo(cube_1, Vector2f(420, 175), dt, 50);
                //moveTo(cube_8, Vector2f(550, 175), dt, 50);
                //moveTo(cube_3, Vector2f(550, 175), dt, 50);
                //moveTo(cube_8, Vector2f(680, 175), dt, 50);
                //moveTo(cube_7, Vector2f(680, 175), dt, 50);
                //moveTo(cube_8, Vector2f(810, 175), dt, 50);
                //moveTo(cube_5, Vector2f(810, 175), dt, 50);
                moveTo(cube_8, Vector2f(940, 175), dt, 50);
                //moveTo(cube_1, Vector2f(290, 175), dt, 50);
                //moveTo(cube_6, Vector2f(420, 175), dt, 50);
                //moveTo(cube_3, Vector2f(420, 175), dt, 50);
                //moveTo(cube_6, Vector2f(550, 175), dt, 50);
                //moveTo(cube_5, Vector2f(680, 175), dt, 50);
                moveTo(cube_7, Vector2f(810, 175), dt, 50);
                //moveTo(cube_1, Vector2f(160, 175), dt, 50);
                //moveTo(cube_4, Vector2f(290, 175), dt, 50);
                moveTo(cube_3, Vector2f(290, 175), dt, 50);
                moveTo(cube_4, Vector2f(420, 175), dt, 50);
                moveTo(cube_5, Vector2f(550, 175), dt, 50);
                moveTo(cube_6, Vector2f(680, 175), dt, 50);
                moveTo(cube_1, Vector2f(30, 175), dt, 50);
                moveTo(cube_2, Vector2f(160, 175), dt, 50);

            }
            if (bubble_sort_num == 2)
            {
                window_bubble_sort.close();
            }
        }

        window_bubble_sort.clear();
        
        text.setString(L"Это сортировка пузырьком! Мы сравниваем ");
        text.setPosition(100, 530);
        text2.setString(L"два соседних числа и меняем местами, если");
        text2.setPosition(100, 550);
        text3.setString(L"они стоят не по порядку. Продолжаем :)");
        text3.setPosition(100, 570);

        window_bubble_sort.draw(background_sorts);
        window_bubble_sort.draw(button_start);
        window_bubble_sort.draw(button_exit);
        window_bubble_sort.draw(character);
        window_bubble_sort.draw(text_dialog);
        window_bubble_sort.draw(cube_1);
        window_bubble_sort.draw(cube_2);
        window_bubble_sort.draw(cube_3);
        window_bubble_sort.draw(cube_4);
        window_bubble_sort.draw(cube_5);
        window_bubble_sort.draw(cube_6);
        window_bubble_sort.draw(cube_7);
        window_bubble_sort.draw(cube_8);
        window_bubble_sort.draw(text);
        window_bubble_sort.draw(text2);
        window_bubble_sort.draw(text3);

        window_bubble_sort.display();
        
    }
}

void shake_sort()
{
    RenderWindow window_shake_sort(VideoMode(1070, 700), "Shake Sort");
    window_shake_sort.setFramerateLimit(60);

    //Графика
    Texture background_sorts_texture, button_start_texture, button_exit_texture, character_texture, text_dialog_texture;
    background_sorts_texture.loadFromFile("images/background_sorts.png");
    button_start_texture.loadFromFile("images/button_start.png");
    button_exit_texture.loadFromFile("images/button_exit.png");
    character_texture.loadFromFile("images/character.png");
    text_dialog_texture.loadFromFile("images/text_dialog.png");
    Sprite background_sorts(background_sorts_texture), button_start(button_start_texture), button_exit(button_exit_texture), character(character_texture), text_dialog(text_dialog_texture);
    background_sorts.setPosition(0, 0);
    button_start.setPosition(30, 350);
    button_exit.setPosition(300, 350);
    character.setPosition(500, 300);
    text_dialog.setPosition(100, 500);
    Texture cube_1_texture, cube_2_texture, cube_3_texture, cube_4_texture, cube_5_texture, cube_6_texture, cube_7_texture, cube_8_texture;
    cube_1_texture.loadFromFile("images/cube_1.png");
    cube_2_texture.loadFromFile("images/cube_2.png");
    cube_3_texture.loadFromFile("images/cube_3.png");
    cube_4_texture.loadFromFile("images/cube_4.png");
    cube_5_texture.loadFromFile("images/cube_5.png");
    cube_6_texture.loadFromFile("images/cube_6.png");
    cube_7_texture.loadFromFile("images/cube_7.png");
    cube_8_texture.loadFromFile("images/cube_8.png");
    Sprite cube_1(cube_1_texture), cube_2(cube_2_texture), cube_3(cube_3_texture), cube_4(cube_4_texture), cube_5(cube_5_texture), cube_6(cube_6_texture), cube_7(cube_7_texture), cube_8(cube_8_texture);
    cube_1.setPosition(550, 175);
    cube_2.setPosition(160, 175);
    cube_3.setPosition(680, 175);
    cube_4.setPosition(30, 175);
    cube_5.setPosition(940, 175);
    cube_6.setPosition(290, 175);
    cube_7.setPosition(810, 175);
    cube_8.setPosition(420, 175);

    Clock clock;
    float speed = 100.0f;
    Vector2f position = button_start.getPosition();

    int shake_sort_num = 0;

    Font font;
    font.loadFromFile("Raleway-Regular.ttf");
    Text text("", font, 20);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);
    Text text2("", font, 20);
    text2.setFillColor(Color::Black);
    text2.setStyle(Text::Bold);
    Text text3("", font, 20);
    text3.setFillColor(Color::Black);
    text3.setStyle(Text::Bold);
    Text text4("", font, 20);
    text4.setFillColor(Color::Black);
    text4.setStyle(Text::Bold);

    while (window_shake_sort.isOpen())
    {
        Event event;
        while (window_shake_sort.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window_shake_sort.close();
        }

        shake_sort_num = 0;
        float dt = clock.restart().asSeconds();

        if (IntRect(30, 350, 270, 450).contains(Mouse::getPosition(window_shake_sort))) { shake_sort_num = 1; }
        if (IntRect(300, 350, 540, 450).contains(Mouse::getPosition(window_shake_sort))) { shake_sort_num = 2; }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (shake_sort_num == 1) //30, 160, 290, 420, 550, 680, 810, 940 - координаты позиций
            {
                //moveTo(cube_2, Vector2f(30, 175), dt, 50);
                //moveTo(cube_4, Vector2f(160, 175), dt, 50);
                //moveTo(cube_1, Vector2f(420, 175), dt, 50);
                //moveTo(cube_8, Vector2f(550, 175), dt, 50);
                //moveTo(cube_3, Vector2f(550, 175), dt, 50);
                //moveTo(cube_8, Vector2f(680, 175), dt, 50);
                //moveTo(cube_7, Vector2f(680, 175), dt, 50);
                //moveTo(cube_8, Vector2f(810, 175), dt, 50);
                //moveTo(cube_5, Vector2f(810, 175), dt, 50);
                moveTo(cube_8, Vector2f(940, 175), dt, 50);
                //moveTo(cube_5, Vector2f(680, 175), dt, 50);
                moveTo(cube_7, Vector2f(810, 175), dt, 50);
                //moveTo(cube_1, Vector2f(290, 175), dt, 50);
                //moveTo(cube_6, Vector2f(420, 175), dt, 50);
                //moveTo(cube_1, Vector2f(160, 175), dt, 50);
                //moveTo(cube_4, Vector2f(290, 175), dt, 50);
                moveTo(cube_1, Vector2f(30, 175), dt, 50);
                moveTo(cube_2, Vector2f(160, 175), dt, 50);
                moveTo(cube_5, Vector2f(550, 175), dt, 50);
                moveTo(cube_6, Vector2f(680, 175), dt, 50);
                moveTo(cube_3, Vector2f(290, 175), dt, 50);
                moveTo(cube_4, Vector2f(420, 175), dt, 50);
            }
            if (shake_sort_num == 2)
            {
                window_shake_sort.close();
            }
        }

        window_shake_sort.clear();
        
        text.setString(L"Это шейкерная сортировка! Принцип тот");
        text.setPosition(100, 530);
        text2.setString(L"же что и в пузырьковой сортировки, ");
        text2.setPosition(100, 550);
        text3.setString(L"только мы идем ещё и в обратную");
        text3.setPosition(100, 570);
        text4.setString(L"сторону. Продолжаем :)");
        text4.setPosition(100, 590);

        window_shake_sort.draw(background_sorts);
        window_shake_sort.draw(button_start);
        window_shake_sort.draw(button_exit);
        window_shake_sort.draw(character);
        window_shake_sort.draw(text_dialog);
        window_shake_sort.draw(cube_1);
        window_shake_sort.draw(cube_2);
        window_shake_sort.draw(cube_3);
        window_shake_sort.draw(cube_4);
        window_shake_sort.draw(cube_5);
        window_shake_sort.draw(cube_6);
        window_shake_sort.draw(cube_7);
        window_shake_sort.draw(cube_8);
        window_shake_sort.draw(text);
        window_shake_sort.draw(text2);
        window_shake_sort.draw(text3);
        window_shake_sort.draw(text4);

        window_shake_sort.display();
    }
}
void addition_sort()
{
    RenderWindow window_addition_sort(VideoMode(1070, 700), "Addition Sort");
    window_addition_sort.setFramerateLimit(60);

    //Графика
    Texture background_sorts_texture, button_start_texture, button_exit_texture, character_texture, text_dialog_texture;
    background_sorts_texture.loadFromFile("images/background_sorts.png");
    button_start_texture.loadFromFile("images/button_start.png");
    button_exit_texture.loadFromFile("images/button_exit.png");
    character_texture.loadFromFile("images/character.png");
    text_dialog_texture.loadFromFile("images/text_dialog.png");
    Sprite background_sorts(background_sorts_texture), button_start(button_start_texture), button_exit(button_exit_texture), character(character_texture), text_dialog(text_dialog_texture);
    background_sorts.setPosition(0, 0);
    button_start.setPosition(30, 350);
    button_exit.setPosition(300, 350);
    character.setPosition(500, 300);
    text_dialog.setPosition(100, 500);
    Texture cube_1_texture, cube_2_texture, cube_3_texture, cube_4_texture, cube_5_texture, cube_6_texture, cube_7_texture, cube_8_texture;
    cube_1_texture.loadFromFile("images/cube_1.png");
    cube_2_texture.loadFromFile("images/cube_2.png");
    cube_3_texture.loadFromFile("images/cube_3.png");
    cube_4_texture.loadFromFile("images/cube_4.png");
    cube_5_texture.loadFromFile("images/cube_5.png");
    cube_6_texture.loadFromFile("images/cube_6.png");
    cube_7_texture.loadFromFile("images/cube_7.png");
    cube_8_texture.loadFromFile("images/cube_8.png");
    Sprite cube_1(cube_1_texture), cube_2(cube_2_texture), cube_3(cube_3_texture), cube_4(cube_4_texture), cube_5(cube_5_texture), cube_6(cube_6_texture), cube_7(cube_7_texture), cube_8(cube_8_texture);
    cube_1.setPosition(550, 175);
    cube_2.setPosition(160, 175);
    cube_3.setPosition(680, 175);
    cube_4.setPosition(30, 175);
    cube_5.setPosition(940, 175);
    cube_6.setPosition(290, 175);
    cube_7.setPosition(810, 175);
    cube_8.setPosition(420, 175);

    Clock clock;
    float speed = 100.0f;
    Vector2f position = button_start.getPosition();

    int addition_sort_num = 0;

    Font font;
    font.loadFromFile("Raleway-Regular.ttf");
    Text text("", font, 20);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);
    Text text2("", font, 20);
    text2.setFillColor(Color::Black);
    text2.setStyle(Text::Bold);
    Text text3("", font, 20);
    text3.setFillColor(Color::Black);
    text3.setStyle(Text::Bold);
    Text text4("", font, 20);
    text4.setFillColor(Color::Black);
    text4.setStyle(Text::Bold);

    while (window_addition_sort.isOpen())
    {
        Event event;
        while (window_addition_sort.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window_addition_sort.close();
        }

        addition_sort_num = 0;
        float dt = clock.restart().asSeconds();

        if (IntRect(30, 350, 270, 450).contains(Mouse::getPosition(window_addition_sort))) { addition_sort_num = 1; }
        if (IntRect(300, 350, 540, 450).contains(Mouse::getPosition(window_addition_sort))) { addition_sort_num = 2; }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (addition_sort_num == 1) //30, 160, 290, 420, 550, 680, 810, 940 - координаты позиций
            {
                //moveTo(cube_2, Vector2f(30, 175), dt, 50);
                //moveTo(cube_4, Vector2f(160, 175), dt, 50);
                moveTo(cube_1, Vector2f(30, 175), dt, 50);
                //moveTo(cube_8, Vector2f(550, 175), dt, 50);
                //moveTo(cube_6, Vector2f(420, 175), dt, 50);
                //moveTo(cube_4, Vector2f(290, 175), dt, 50);
                moveTo(cube_2, Vector2f(160, 175), dt, 50);
                moveTo(cube_3, Vector2f(290, 175), dt, 50);
                //moveTo(cube_8, Vector2f(680, 175), dt, 50);
                //moveTo(cube_6, Vector2f(550, 175), dt, 50);
                moveTo(cube_4, Vector2f(420, 175), dt, 50);
                //moveTo(cube_7, Vector2f(680, 175), dt, 50);
                moveTo(cube_5, Vector2f(550, 175), dt, 50);
                moveTo(cube_8, Vector2f(940, 175), dt, 50);
                moveTo(cube_7, Vector2f(810, 175), dt, 50);
                moveTo(cube_6, Vector2f(680, 175), dt, 50);
            }
            if (addition_sort_num == 2)
            {
                window_addition_sort.close();
            }
        }

        window_addition_sort.clear();

        text.setString(L"Это сортировка вставками! Мы делим список");
        text.setPosition(100, 530);
        text2.setString(L"на отрорт. и неотсорт.. Берем элемент из");
        text2.setPosition(100, 550);
        text3.setString(L" неотсортированного и вставляем в нужное");
        text3.setPosition(100, 570);
        text4.setString(L" место отсортированного. Продолжаем :)");
        text4.setPosition(100, 590);

        window_addition_sort.draw(background_sorts);
        window_addition_sort.draw(button_start);
        window_addition_sort.draw(button_exit);
        window_addition_sort.draw(character);
        window_addition_sort.draw(text_dialog);
        window_addition_sort.draw(cube_1);
        window_addition_sort.draw(cube_2);
        window_addition_sort.draw(cube_3);
        window_addition_sort.draw(cube_4);
        window_addition_sort.draw(cube_5);
        window_addition_sort.draw(cube_6);
        window_addition_sort.draw(cube_7);
        window_addition_sort.draw(cube_8);
        window_addition_sort.draw(text);
        window_addition_sort.draw(text2);
        window_addition_sort.draw(text3);
        window_addition_sort.draw(text4);

        window_addition_sort.display();
    }

}
void Shella_sort()
{
    RenderWindow window_Shella_sort(VideoMode(1070, 700), "Shella Sort");
    window_Shella_sort.setFramerateLimit(60);

    //Графика
    Texture background_sorts_texture, button_start_texture, button_exit_texture, character_texture, text_dialog_texture;
    background_sorts_texture.loadFromFile("images/background_sorts.png");
    button_start_texture.loadFromFile("images/button_start.png");
    button_exit_texture.loadFromFile("images/button_exit.png");
    character_texture.loadFromFile("images/character.png");
    text_dialog_texture.loadFromFile("images/text_dialog.png");
    Sprite background_sorts(background_sorts_texture), button_start(button_start_texture), button_exit(button_exit_texture), character(character_texture), text_dialog(text_dialog_texture);
    background_sorts.setPosition(0, 0);
    button_start.setPosition(30, 350);
    button_exit.setPosition(300, 350);
    character.setPosition(500, 300);
    text_dialog.setPosition(100, 500);
    Texture cube_1_texture, cube_2_texture, cube_3_texture, cube_4_texture, cube_5_texture, cube_6_texture, cube_7_texture, cube_8_texture;
    cube_1_texture.loadFromFile("images/cube_1.png");
    cube_2_texture.loadFromFile("images/cube_2.png");
    cube_3_texture.loadFromFile("images/cube_3.png");
    cube_4_texture.loadFromFile("images/cube_4.png");
    cube_5_texture.loadFromFile("images/cube_5.png");
    cube_6_texture.loadFromFile("images/cube_6.png");
    cube_7_texture.loadFromFile("images/cube_7.png");
    cube_8_texture.loadFromFile("images/cube_8.png");
    Sprite cube_1(cube_1_texture), cube_2(cube_2_texture), cube_3(cube_3_texture), cube_4(cube_4_texture), cube_5(cube_5_texture), cube_6(cube_6_texture), cube_7(cube_7_texture), cube_8(cube_8_texture);
    cube_1.setPosition(550, 175);
    cube_2.setPosition(160, 175);
    cube_3.setPosition(680, 175);
    cube_4.setPosition(30, 175);
    cube_5.setPosition(940, 175);
    cube_6.setPosition(290, 175);
    cube_7.setPosition(810, 175);
    cube_8.setPosition(420, 175);

    Clock clock;
    float speed = 100.0f;
    Vector2f position = button_start.getPosition();

    int Shella_sort_num = 0;

    Font font;
    font.loadFromFile("Raleway-Regular.ttf");
    Text text("", font, 20);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);
    Text text2("", font, 20);
    text2.setFillColor(Color::Black);
    text2.setStyle(Text::Bold);
    Text text3("", font, 20);
    text3.setFillColor(Color::Black);
    text3.setStyle(Text::Bold);
    Text text4("", font, 20);
    text4.setFillColor(Color::Black);
    text4.setStyle(Text::Bold);

    while (window_Shella_sort.isOpen())
    {
        Event event;
        while (window_Shella_sort.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window_Shella_sort.close();
        }

        Shella_sort_num = 0;
        float dt = clock.restart().asSeconds();

        if (IntRect(30, 350, 270, 450).contains(Mouse::getPosition(window_Shella_sort))) { Shella_sort_num = 1; }
        if (IntRect(300, 350, 540, 450).contains(Mouse::getPosition(window_Shella_sort))) { Shella_sort_num = 2; }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (Shella_sort_num == 1) //30, 160, 290, 420, 550, 680, 810, 940 - координаты позиций
            {
                moveTo(cube_1, Vector2f(30, 175), dt, 50);
                //moveTo(cube_4, Vector2f(550, 175), dt, 50);
                //moveTo(cube_5, Vector2f(420, 175), dt, 50);
                moveTo(cube_8, Vector2f(940, 175), dt, 50);
                //moveTo(cube_4, Vector2f(290, 175), dt, 50);
                //moveTo(cube_6, Vector2f(550, 175), dt, 50);
                //moveTo(cube_3, Vector2f(420, 175), dt, 50);
                //moveTo(cube_5, Vector2f(680, 175), dt, 50);
                moveTo(cube_3, Vector2f(290, 175), dt, 50);
                moveTo(cube_4, Vector2f(420, 175), dt, 50);
                moveTo(cube_5, Vector2f(550, 175), dt, 50);
                moveTo(cube_6, Vector2f(680, 175), dt, 50);
            }
            if (Shella_sort_num == 2)
            {
                window_Shella_sort.close();
            }
        }

        window_Shella_sort.clear();

        text.setString(L"Это сортировка Шелла! Мы вводим шаг (n/2)");
        text.setPosition(100, 530);
        text2.setString(L"и рассматриваем элементы с шагом. Меняем");
        text2.setPosition(100, 550);
        text3.setString(L"при необходимости. Уменьшаем шаг в 2 раза.");
        text3.setPosition(100, 570);
        text4.setString(L"Продолжаем :)");
        text4.setPosition(100, 590);

        window_Shella_sort.draw(background_sorts);
        window_Shella_sort.draw(button_start);
        window_Shella_sort.draw(button_exit);
        window_Shella_sort.draw(character);
        window_Shella_sort.draw(text_dialog);
        window_Shella_sort.draw(cube_1);
        window_Shella_sort.draw(cube_2);
        window_Shella_sort.draw(cube_3);
        window_Shella_sort.draw(cube_4);
        window_Shella_sort.draw(cube_5);
        window_Shella_sort.draw(cube_6);
        window_Shella_sort.draw(cube_7);
        window_Shella_sort.draw(cube_8);
        window_Shella_sort.draw(text);
        window_Shella_sort.draw(text2);
        window_Shella_sort.draw(text3);
        window_Shella_sort.draw(text4);

        window_Shella_sort.display();
    }

}
void choosing_sort()
{
    RenderWindow window_choosing_sort(VideoMode(1070, 700), "Choosing Sort");
    window_choosing_sort.setFramerateLimit(60);

    //Графика
    Texture background_sorts_texture, button_start_texture, button_exit_texture, character_texture, text_dialog_texture;
    background_sorts_texture.loadFromFile("images/background_sorts.png");
    button_start_texture.loadFromFile("images/button_start.png");
    button_exit_texture.loadFromFile("images/button_exit.png");
    character_texture.loadFromFile("images/character.png");
    text_dialog_texture.loadFromFile("images/text_dialog.png");
    Sprite background_sorts(background_sorts_texture), button_start(button_start_texture), button_exit(button_exit_texture), character(character_texture), text_dialog(text_dialog_texture);
    background_sorts.setPosition(0, 0);
    button_start.setPosition(30, 350);
    button_exit.setPosition(300, 350);
    character.setPosition(500, 300);
    text_dialog.setPosition(100, 500);
    Texture cube_1_texture, cube_2_texture, cube_3_texture, cube_4_texture, cube_5_texture, cube_6_texture, cube_7_texture, cube_8_texture;
    cube_1_texture.loadFromFile("images/cube_1.png");
    cube_2_texture.loadFromFile("images/cube_2.png");
    cube_3_texture.loadFromFile("images/cube_3.png");
    cube_4_texture.loadFromFile("images/cube_4.png");
    cube_5_texture.loadFromFile("images/cube_5.png");
    cube_6_texture.loadFromFile("images/cube_6.png");
    cube_7_texture.loadFromFile("images/cube_7.png");
    cube_8_texture.loadFromFile("images/cube_8.png");
    Sprite cube_1(cube_1_texture), cube_2(cube_2_texture), cube_3(cube_3_texture), cube_4(cube_4_texture), cube_5(cube_5_texture), cube_6(cube_6_texture), cube_7(cube_7_texture), cube_8(cube_8_texture);
    cube_1.setPosition(550, 175);
    cube_2.setPosition(160, 175);
    cube_3.setPosition(680, 175);
    cube_4.setPosition(30, 175);
    cube_5.setPosition(940, 175);
    cube_6.setPosition(290, 175);
    cube_7.setPosition(810, 175);
    cube_8.setPosition(420, 175);

    Clock clock;
    float speed = 100.0f;
    Vector2f position = button_start.getPosition();

    int choosing_sort_num = 0;

    Font font;
    font.loadFromFile("Raleway-Regular.ttf");
    Text text("", font, 20);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);
    Text text2("", font, 20);
    text2.setFillColor(Color::Black);
    text2.setStyle(Text::Bold);
    Text text3("", font, 20);
    text3.setFillColor(Color::Black);
    text3.setStyle(Text::Bold);
    Text text4("", font, 20);
    text4.setFillColor(Color::Black);
    text4.setStyle(Text::Bold);

    while (window_choosing_sort.isOpen())
    {
        Event event;
        while (window_choosing_sort.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window_choosing_sort.close();
        }

        choosing_sort_num = 0;
        float dt = clock.restart().asSeconds();

        if (IntRect(30, 350, 270, 450).contains(Mouse::getPosition(window_choosing_sort))) { choosing_sort_num = 1; }
        if (IntRect(300, 350, 540, 450).contains(Mouse::getPosition(window_choosing_sort))) { choosing_sort_num = 2; }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (choosing_sort_num == 1) //30, 160, 290, 420, 550, 680, 810, 940 - координаты позиций
            {
                //moveTo(cube_1, Vector2f(30, 175), dt, 50);
                moveTo(cube_1, Vector2f(30, 175), dt, 50);
                //moveTo(cube_8, Vector2f(550, 175), dt, 50);
                //moveTo(cube_6, Vector2f(420, 175), dt, 50);
                //moveTo(cube_2, Vector2f(290, 175), dt, 50);
                //moveTo(cube_4, Vector2f(160, 175), dt, 50);
                moveTo(cube_2, Vector2f(160, 175), dt, 50);
                //moveTo(cube_4, Vector2f(290, 175), dt, 50);
                moveTo(cube_3, Vector2f(290, 175), dt, 50);
                //moveTo(cube_8, Vector2f(680, 175), dt, 50);
                //moveTo(cube_6, Vector2f(550, 175), dt, 50);
                moveTo(cube_4, Vector2f(420, 175), dt, 50);
                moveTo(cube_5, Vector2f(550, 175), dt, 50);
                //moveTo(cube_7, Vector2f(940, 175), dt, 50);
                //moveTo(cube_8, Vector2f(810, 175), dt, 50);
                moveTo(cube_6, Vector2f(680, 175), dt, 50);
                moveTo(cube_7, Vector2f(810, 175), dt, 50);
                moveTo(cube_8, Vector2f(940, 175), dt, 50);
            }
            if (choosing_sort_num == 2)
            {
                window_choosing_sort.close();
            }
        }

        window_choosing_sort.clear();

        text.setString(L"Это сортировка выбором! Мы выбираем ");
        text.setPosition(100, 530);
        text2.setString(L"наименьшее число, путем сравнения с ");
        text2.setPosition(100, 550);
        text3.setString(L"найденным ранее минимумом. Ставим в ");
        text3.setPosition(100, 570);
        text4.setString(L"конец отсорт. списка. Продолжаем :)");
        text4.setPosition(100, 590);

        window_choosing_sort.draw(background_sorts);
        window_choosing_sort.draw(button_start);
        window_choosing_sort.draw(button_exit);
        window_choosing_sort.draw(character);
        window_choosing_sort.draw(text_dialog);
        window_choosing_sort.draw(cube_1);
        window_choosing_sort.draw(cube_2);
        window_choosing_sort.draw(cube_3);
        window_choosing_sort.draw(cube_4);
        window_choosing_sort.draw(cube_5);
        window_choosing_sort.draw(cube_6);
        window_choosing_sort.draw(cube_7);
        window_choosing_sort.draw(cube_8);
        window_choosing_sort.draw(text);
        window_choosing_sort.draw(text2);
        window_choosing_sort.draw(text3);
        window_choosing_sort.draw(text4);

        window_choosing_sort.display();
    }

}
void saming_sort()
{
    RenderWindow window_saming_sort(VideoMode(1070, 700), "Saming Sort");
    window_saming_sort.setFramerateLimit(60);

    //Графика
    Texture background_sorts_texture, button_start_texture, button_exit_texture, character_texture, text_dialog_texture;
    background_sorts_texture.loadFromFile("images/background_sorts.png");
    button_start_texture.loadFromFile("images/button_start.png");
    button_exit_texture.loadFromFile("images/button_exit.png");
    character_texture.loadFromFile("images/character.png");
    text_dialog_texture.loadFromFile("images/text_dialog.png");
    Sprite background_sorts(background_sorts_texture), button_start(button_start_texture), button_exit(button_exit_texture), character(character_texture), text_dialog(text_dialog_texture);
    background_sorts.setPosition(0, 0);
    button_start.setPosition(30, 350);
    button_exit.setPosition(300, 350);
    character.setPosition(500, 300);
    text_dialog.setPosition(100, 500);
    Texture cube_1_texture, cube_2_texture, cube_3_texture, cube_4_texture, cube_5_texture, cube_6_texture, cube_7_texture, cube_8_texture;
    cube_1_texture.loadFromFile("images/cube_1.png");
    cube_2_texture.loadFromFile("images/cube_2.png");
    cube_3_texture.loadFromFile("images/cube_3.png");
    cube_4_texture.loadFromFile("images/cube_4.png");
    cube_5_texture.loadFromFile("images/cube_5.png");
    cube_6_texture.loadFromFile("images/cube_6.png");
    cube_7_texture.loadFromFile("images/cube_7.png");
    cube_8_texture.loadFromFile("images/cube_8.png");
    Sprite cube_1(cube_1_texture), cube_2(cube_2_texture), cube_3(cube_3_texture), cube_4(cube_4_texture), cube_5(cube_5_texture), cube_6(cube_6_texture), cube_7(cube_7_texture), cube_8(cube_8_texture);
    cube_1.setPosition(550, 175);
    cube_2.setPosition(160, 175);
    cube_3.setPosition(680, 175);
    cube_4.setPosition(30, 175);
    cube_5.setPosition(940, 175);
    cube_6.setPosition(290, 175);
    cube_7.setPosition(810, 175);
    cube_8.setPosition(420, 175);

    Clock clock;
    float speed = 100.0f;
    Vector2f position = button_start.getPosition();

    int saming_sort_num = 0;

    Font font;
    font.loadFromFile("Raleway-Regular.ttf");
    Text text("", font, 20);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);
    Text text2("", font, 20);
    text2.setFillColor(Color::Black);
    text2.setStyle(Text::Bold);
    Text text3("", font, 20);
    text3.setFillColor(Color::Black);
    text3.setStyle(Text::Bold);
    Text text4("", font, 20);
    text4.setFillColor(Color::Black);
    text4.setStyle(Text::Bold);

    while (window_saming_sort.isOpen())
    {
        Event event;
        while (window_saming_sort.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window_saming_sort.close();
        }

        saming_sort_num = 0;
        float dt = clock.restart().asSeconds();

        if (IntRect(30, 350, 270, 450).contains(Mouse::getPosition(window_saming_sort))) { saming_sort_num = 1; }
        if (IntRect(300, 350, 540, 450).contains(Mouse::getPosition(window_saming_sort))) { saming_sort_num = 2; }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (saming_sort_num == 1) //30, 160, 290, 420, 550, 680, 810, 940 - координаты позиций
            {
                //moveTo(cube_2, Vector2f(30, 175), dt, 50);
                //moveTo(cube_4, Vector2f(160, 175), dt, 50);
                //moveTo(cube_5, Vector2f(810, 175), dt, 50);
                //moveTo(cube_7, Vector2f(940, 175), dt, 50);
                moveTo(cube_1, Vector2f(30, 175), dt, 50);
                //moveTo(cube_8, Vector2f(550, 175), dt, 50);
                //moveTo(cube_6, Vector2f(420, 175), dt, 50);
                //moveTo(cube_4, Vector2f(290, 175), dt, 50);
                moveTo(cube_2, Vector2f(160, 175), dt, 50);
                moveTo(cube_3, Vector2f(290, 175), dt, 50);
                //moveTo(cube_8, Vector2f(680, 175), dt, 50);
                //moveTo(cube_6, Vector2f(550, 175), dt, 50);
                moveTo(cube_4, Vector2f(420, 175), dt, 50);
                moveTo(cube_5, Vector2f(550, 175), dt, 50);
                //moveTo(cube_8, Vector2f(810, 175), dt, 50);
                moveTo(cube_6, Vector2f(680, 175), dt, 50);
                moveTo(cube_7, Vector2f(810, 175), dt, 50);
                moveTo(cube_8, Vector2f(940, 175), dt, 50);
            }
            if (saming_sort_num == 2)
            {
                window_saming_sort.close();
            }
        }

        window_saming_sort.clear();

        text.setString(L"Это сортировка слиянием! Мы делим список");
        text.setPosition(100, 530);
        text2.setString(L"пополам пока не останется по одному ");
        text2.setPosition(100, 550);
        text3.setString(L"элементу. Затем начинаем сравнивать ");
        text3.setPosition(100, 570);
        text4.setString(L"первые элементы списков. Продолжаем :)");
        text4.setPosition(100, 590);

        window_saming_sort.draw(background_sorts);
        window_saming_sort.draw(button_start);
        window_saming_sort.draw(button_exit);
        window_saming_sort.draw(character);
        window_saming_sort.draw(text_dialog);
        window_saming_sort.draw(cube_1);
        window_saming_sort.draw(cube_2);
        window_saming_sort.draw(cube_3);
        window_saming_sort.draw(cube_4);
        window_saming_sort.draw(cube_5);
        window_saming_sort.draw(cube_6);
        window_saming_sort.draw(cube_7);
        window_saming_sort.draw(cube_8);
        window_saming_sort.draw(text);
        window_saming_sort.draw(text2);
        window_saming_sort.draw(text3);
        window_saming_sort.draw(text4);

        window_saming_sort.display();
    }

}

int main()
{
    RenderWindow window(VideoMode(1070, 700), "Menu");
    menu(window);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}
