#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

using namespace std;
sf::RenderWindow window(sf::VideoMode(900, 900), "GAME" ,sf::Style::Fullscreen);
bool startScreen1=true;
bool startScreen3=false;
int intial_time;
bool notifyGood= false; bool notifyBad=false; bool finishGame=false;
int choosed=-1;
int chance = 3;
int at_recipe=0;
int recipe_order[5] ={-1,-1,-1,-1,-1};
int i_random=0;

int choice=1;
int mode=0; //mode is set to 0 because it is the first that is displayed
int find(int num){
    for(int i = 0; i < 5; i++){
        if(recipe_order[i] == num){
            return i;
        }
    }
}
void randomizeArray(){
    int i;
    int numbers[5]={0,1,2,3,4};
    int count=0;
    while(count != 5){
        i = rand()%5;
        if(numbers[i] != -1){
            recipe_order[count]=numbers[i];
            numbers[i] = -1;
            count++;
        }
    }
}
void startScreen(){
    sf:: Font font;
    font.loadFromFile("sansation.ttf");



    sf::Text text_foods;
    sf::Text text_shiro;
    sf::Text text_anebabero;
    sf::Text text_tibs;

    text_foods.setFont(font);
    text_shiro.setFont(font);
    text_anebabero.setFont(font);
    text_tibs.setFont(font);
    text_foods.setString("We have three foods for you \n");
    text_shiro.setString("Shiro");
    text_anebabero.setString("Anebabero");
    text_tibs.setString("Tibs");
    text_foods.setPosition(610, 40);
    text_shiro.setPosition(100,300);
    text_anebabero.setPosition(600,300);
    text_tibs.setPosition(1000,300);
    sf::Text text_continue;
    text_continue.setFont(font);
    text_continue.setString("Press ENTER to continue ");
    text_continue.setPosition(550, 600);
     sf::Text text_back;
    text_back.setFont(font);
    text_back.setString("To Go Back  press BACKSPACE");
    text_back.setPosition(10, 730);
   sf::Texture shiro;
    shiro.loadFromFile("images.jpg");
    sf::Sprite shiroo;
    shiroo.setTexture(shiro);
  //  sp.setScale(1.5,1.0);
  shiroo.setPosition(100,100);



 sf::Texture anebabero;
    anebabero.loadFromFile("Capture.jpg");
    sf::Sprite anebaberoo;
    anebaberoo.setScale(1.0,1.3);
    anebaberoo.setTexture(anebabero);
    anebaberoo.setPosition(600,100) ;

      sf::Texture tibs;
    tibs.loadFromFile("tibs.png");
    sf::Sprite tibss;
    tibss.setScale(0.8,1.2);
   tibss.setTexture(tibs);
   tibss.setPosition(1000, 100);



    if(!startScreen3){
        std::srand(std::time(NULL));
        i_random = rand()%3;
        randomizeArray(); //it shuffles the recipe_order
    }


     std::string foods[3]={"Shiro", "Anebabero", "Tibs"};
    std::string food_recipe[3][5]={{"Oil", "Onion", "Tomato", "Shiro", "Other ingredients"},
        {"Kita", "Oil", "Spice", "Other Ingredient", "Additional kita"},
        {"Oil", "Onion", "Meat", "Tomato", "Pepper"},
    };

   sf::Text text_message1;
    text_message1.setFont(font);
    text_message1.setString("We have 3 cooks for you!\n");
    text_message1.setPosition(400, 100);

    sf::Text text_message2;
    text_message2.setFont(font);
    text_message2.setString("From the three cooks, the machine chooses: \n");
    text_message2.setPosition(200, 130);

    sf::Text text_message21;
    text_message21.setFont(font);
    text_message21.setString(foods[i_random]);
    text_message21.setPosition(850, 130);

    sf::Text text_message3;
    text_message3.setFont(font);
    text_message3.setString("YOU HAVE " + std::to_string(chance) + " lives \n");
    text_message3.setPosition(550, 100);

    sf::Text text_message31;
    text_message31.setFont(font);
    text_message31.setString("1." + food_recipe [i_random] [recipe_order[0] ] + "\n");
    text_message31.setPosition(550, 150);



    sf::Text text_message5;
    text_message5.setFont(font);
    text_message5.setString( "2. " + food_recipe[i_random][recipe_order[1]] + "\n");
    text_message5.setPosition(550, 200);



    sf::Text text_message6;
    text_message6.setFont(font);
    text_message6.setString( "3. " + food_recipe[i_random][recipe_order[2]] + "\n");
    text_message6.setPosition(550, 250);



    sf::Text text_message7;
    text_message7.setFont(font);
    text_message7.setString( "4. " + food_recipe[i_random][recipe_order[3]] + "\n");
    text_message7.setPosition(550, 300);



    sf::Text text_message8;
    text_message8.setFont(font);
    text_message8.setString( "5. " + food_recipe[i_random][recipe_order[4]] + "\n");
    text_message8.setPosition(550, 350);





    sf::Text text_message9;
    text_message9.setFont(font);
    text_message9.setString("Enter your choice: ");
    text_message9.setPosition(550, 500);


    sf::Text text_message11;
    text_message11.setFont(font);
    text_message11.setString("You are right. keep going.\n");
    text_message11.setPosition(550, 550);

    sf::Text text_message12;
    text_message12.setFont(font);
    text_message12.setString("Try again!\n");
    text_message12.setPosition(550, 550);

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(500, 300));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setPosition(10, 330);

    sf::Text text_message15;
    text_message15.setFont(font);
    text_message15.setString("GAME OVER \n Press BackSpace");
    text_message15.setPosition(550, 330);

    sf::Text text_message16;
    text_message16.setFont(font);
    text_message16.setString("YOU WON \n Press BackSpace");
    text_message16.setPosition(550, 330);


    if(!finishGame){
        if(startScreen1){
            window.draw(text_foods);

            window.draw(text_continue);
            window.draw(text_back);
            window.draw(shiroo);
            window.draw(anebaberoo);
            window.draw(tibss);
             window.draw(text_shiro);
            window.draw(text_anebabero);
            window.draw(text_tibs);
        }else if(startScreen3){
            window.clear(sf::Color::Black);
            window.draw(text_message31);
           window.draw(text_message3);

            window.draw(text_message5);

            window.draw(text_message6);

            window.draw(text_message7);

            window.draw(text_message8);

            window.draw(text_message9);
            if(notifyGood){
                window.draw(rectangle);
                window.draw(text_message11);
            }else if (notifyBad){
                window.draw(rectangle);
                window.draw(text_message12);
            }

            if (chance == 0){
                finishGame=true;
            }else if(at_recipe == 4){
                finishGame=true;
            }else{
                if( choosed == 1 or choosed == 2 or choosed == 3 or choosed == 4 or choosed == 5  ){
                    if (find(at_recipe) == choosed - 1){
                        notifyBad=false;
                        notifyGood=true;
                        at_recipe++;
                        choosed=-1;
                    }else {
                        notifyGood=false;
                        notifyBad=true;
                        chance--;
                        choosed=-1;
                    }
                }
        }

        }else if(!startScreen1 and !startScreen3){
            window.clear(sf::Color::Black);
            window.draw(text_message1);
            window.draw(text_message2);
            window.draw(text_message21);
            window.display();
            //to wait 4 seconds before going to next screen
            intial_time=time(NULL);
            while(true){
                int final_time = time(NULL);
                if(final_time - intial_time == 4){
                    break;
                }
            }
            startScreen3=true;
        }
    }else if (finishGame ){
        if(chance == 0){
            window.clear(sf::Color::Black);
            window.draw(text_message15);//game over
            choosed=-1;

            at_recipe=0;

        }else if(chance>0){
            window.clear(sf::Color::Black);
            window.draw(text_message16);//you won
            choosed=-1;
            at_recipe=0;

        }
    }
}

int main()
{
    sf:: Font font;
    font.loadFromFile("sansation.ttf");
      sf::Texture gg;
    gg.loadFromFile("g.jpg");
    sf::Sprite sp;
    sp.setTexture(gg);
    sp.setScale(1.7,1.0);
     sf::Texture g;
    g.loadFromFile("help.jpg");
    sf::Sprite p;
    p.setScale(3.2,3.0);
    p.setTexture(g);



    sf::Text text_start;
    sf::Text text_help;
    sf::Text text_quit;
    sf::Text text_helpInfo;
    sf::Text text_h;
    text_start.setFont(font);
    text_help.setFont(font);
    text_quit.setFont(font);
    text_helpInfo.setFont(font);
        text_h.setFont(font);

    text_start.setString("1. START");
    text_help.setString("2. HELP");
    text_quit.setString("3. QUIT");
     text_h.setString("HELP");
text_helpInfo.setString("This is a simple game where you try to find the correct order\n \t\t\tof ingredients to make a specific Ethiopian dish.");
      text_h.setFillColor(sf::Color::Cyan);
    text_helpInfo.setFillColor(sf::Color::Cyan);

    text_start.setFillColor(sf::Color::Red);
    text_help.setFillColor(sf::Color::White);
    text_quit.setFillColor(sf::Color::White);

    text_start.setPosition(650,450);
    text_help.setPosition(650,495);
    text_quit.setPosition(650, 540);
       text_h.setPosition(610,30);
    text_helpInfo.setPosition(250, 50);
    while (window.isOpen())
    {
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            if(mode == 0){//Home Screen
                //Display First Screen
                 window.draw(sp);

                window.draw(text_start);
                window.draw(text_help);
                window.draw(text_quit);
            }else if(mode == 1){//Start Screen
                window.clear(sf::Color::Black);
                startScreen();
            }else if(mode == 2){//Help Screen
                window.clear();//Help Screen
                window.draw(p);
                window.draw(text_h);
                window.draw(text_helpInfo);
            }else if(mode == 3){
                window.close();
            }

            if (Event.type == sf::Event::Closed)
                window.close();

            if (Event.type == sf::Event::EventType::KeyPressed){
                switch(Event.key.code){
                    case (sf::Keyboard::Up)://Up key pressed
                        if(choice == 1){
                            text_start.setFillColor(sf::Color::White);
                            text_quit.setFillColor(sf::Color::Red);
                            choice=3;
                        }else if(choice == 2){
                            text_help.setFillColor(sf::Color::White);
                            text_start.setFillColor(sf::Color::Red);
                            choice=1;
                        }else if(choice == 3){
                            text_quit.setFillColor(sf::Color::White);
                            text_help.setFillColor(sf::Color::Red);
                            choice=2;
                        }
                        break;
                    case (sf::Keyboard::Down)://Down key pressed
                        if(choice == 1){
                            text_start.setFillColor(sf::Color::White);
                            text_help.setFillColor(sf::Color::Red);
                            choice=2;
                        }else if(choice == 2){
                            text_help.setFillColor(sf::Color::White);
                            text_quit.setFillColor(sf::Color::Red);
                            choice=3;
                        }else if(choice == 3){
                            text_start.setFillColor(sf::Color::Red);
                            text_quit.setFillColor(sf::Color::White);
                            choice=1;
                        }
                        break;
                    case (sf::Keyboard::Return)://Enter key pressed
                        if(mode == 0){
                            if(choice == 1){
                                mode = 1;
                            }else if(choice == 2){
                                mode = 2;
                            }else if(choice == 3){
                                mode = 3;
                            }
                        }else if(mode ==1){
                            startScreen1 = false;

                        }
                        break;
                    case (sf::Keyboard::BackSpace):// BackSpace keyPressed
                        if (mode >= 1){
                            text_start.setFillColor(sf::Color::Red);
                            text_help.setFillColor(sf::Color::White);
                            text_quit.setFillColor(sf::Color::White);
                            startScreen1=true;
                            startScreen3=false;
                            notifyBad=false;
                            notifyGood=false;
                            finishGame=false;
                            at_recipe=0;
                            chance=3;
                            choice = 1;
                            mode=0;
                        }
                    case (sf::Keyboard::Num1):
                        choosed=1;
                        break;
                    case (sf::Keyboard::Num2):
                        choosed=2;
                        break;
                    case (sf::Keyboard::Num3):
                        choosed=3;
                        break;
                    case (sf::Keyboard::Num4):
                        choosed=4;
                        break;
                    case (sf::Keyboard::Num5):
                        choosed=5;
                        break;
                    default:
                        break;
                }
            }



            window.display();
        }
    }
    return 0;
}
