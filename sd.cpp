// Главный цикл приложения
    bool mouseWasPressed = false;
    while (const std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
        if (showTextField && event->is<sf::Event::TextEntered>()) {
			const auto* textentered = event->getIf<sf::Event::TextEntered>();
            if (textentered->unicode >= '0' && textentered->unicode <= '3') {
                inputText = static_cast<char>(textentered->unicode);
                inputTextDisplay.setString(inputText);
            } else if (textentered->unicode == 8 && !inputText.empty()) { // Backspace
                inputText.clear();
                inputTextDisplay.setString("");
            }
        }
        if (showTextField && event->is<sf::Event::KeyPressed>()) {
			const auto* keypressed = event->getIf<sf::Event::KeyPressed>();
            if (keypressed->code == sf::Keyboard::Key::Enter && !inputText.empty()) {
                int input = std::stoi(inputText);
                if (inputState == InputState::Study) {
                    if (input >= 1 && input <= 3) {
                        if (input == 1) {
                            activebody.stud->physic.makeoperation(activebody.stud->stats["bot"], activebody.stud->achieve.numbers[0]);
                        } else if (input == 2) {
                            activebody.stud->math.makeoperation(activebody.stud->stats["bot"], activebody.stud->achieve.numbers[1]);
                        } else {
                            activebody.stud->proga.makeoperation(activebody.stud->stats["bot"], activebody.stud->achieve.numbers[2]);
                        }
                        std::vector<int> studyParams;
                        if (dynamic_cast<Botenjoyer*>(activebody.stud)) {
                            studyParams = { -10, 0, 10, 30, -10 };
                        } else if (dynamic_cast<Chillguy*>(activebody.stud)) {
                            studyParams = { -10, 10, 0, -10, 0 };
                        } else {
                            studyParams = { -10, 10, -10, 0, -10 };
                        }
                        activebody.stud->action(studyParams);
                        activebody.pressthebutton();
                        statusMessage.setString("Studied " + subjects[input]);
                        messageTimer = messageDuration;
                    }
                } else if (inputState == InputState::Achievement) {
                    if (input == 1) {
                        if (achievementSubject == "physic") {
                            activebody.stud->achieve.numbers[0] = 1;
                            statusMessage.setString("Improved physics");
                        } else if (achievementSubject == "math") {
                            activebody.stud->achieve.numbers[1] = 1;
                            statusMessage.setString("Improved math");
                        } else if (achievementSubject == "proga") {
                            activebody.stud->achieve.numbers[2] = 1;
                            statusMessage.setString("Improved programming");
                        }
                    } else {
                        statusMessage.setString("Skipped improvement");
                    }
                    messageTimer = messageDuration;
                }
                showTextField = false;
                inputText.clear();
                inputTextDisplay.setString("");
                inputState = InputState::None;
            }
        }
        if (event->is<sf::Event::MouseButtonPressed>() && event->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
            mouseWasPressed = true;
        }
        if (event->is<sf::Event::MouseButtonReleased>() && mouseWasPressed) {
			const auto* mousereleased = event->getIf<sf::Event::MouseButtonReleased>();
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(mousereleased->position.x, mousereleased->position.y));
            if (!showTextField) {
                for (size_t i = 0; i < buttons.size(); ++i) {
                    if (buttons[i].getGlobalBounds().contains(mousePos)) {
                        if (numbers[i] == 2) { // Study
                            showTextField = true;
                            inputState = InputState::Study;
                            questionText.setString("Choose subject (1: Physics, 2: Math, 3: Proga)");
                        } else {
                            processNumber(numbers[i], &activebody);
                            statusMessage.setString("Performed " + actionLabels[i]);
                            messageTimer = messageDuration;
                        }
                    }
                }
            }
            mouseWasPressed = false;
        }

        // Обновление сообщений
        if (messageTimer > 0) {
            messageTimer -= 0.016f; // Примерно 60 FPS
            if (messageTimer <= 0) {
                statusMessage.setString("");
            }
        }

        // Проверка событий дня и достижений
        if (activebody.number_action == 0 && activebody.days > 0) {
            statusMessage.setString("It is a new day");
            messageTimer = messageDuration;
            int count = std::count(activebody.important_days.begin(), activebody.important_days.end(), activebody.days);
            int cou = std::count(activebody.achievement_days.begin(), activebody.achievement_days.end(), activebody.days);
            if (count > 0) {
                statusMessage.setString("Deadline uiuiui");
                messageTimer = messageDuration;
            }
            if (cou > 0 && !showTextField) {
                std::unordered_map<std::string, int> priv;
                priv["physic"] = activebody.stud->achieve.numbers[0];
                priv["math"] = activebody.stud->achieve.numbers[1];
                priv["proga"] = activebody.stud->achieve.numbers[2];
                std::vector<std::string> arezero;
                for (const auto& pair : priv) {
                    if (pair.second == 0) {
                        arezero.push_back(pair.first);
                    }
                }
                if (!arezero.empty()) {
                    int randomIndex = std::rand() % arezero.size();
                    achievementSubject = arezero[randomIndex];
                    showTextField = true;
                    inputState = InputState::Achievement;
                    questionText.setString("Improve " + achievementSubject + "? (1: Yes, 0: No)");
                }
            }
        }

        // Подсветка кнопок
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        for (size_t i = 0; i < buttons.size(); ++i) {
            buttons[i].setFillColor(buttons[i].getGlobalBounds().contains(mousePos) ? sf::Color(200, 192, 98) : sf::Color(253, 246, 171));
        }

        // Обновление UI
        daytext.setString("Day: " + std::to_string(activebody.days + 1));
        petext.setString(std::to_string(activebody.stud->pe.value));
        for (size_t i = 0; i < barsnumber.size(); ++i) {
            int num = activebody.stud->stats.at(conver.at(i + 1));
            barprogress[i].setSize(sf::Vector2f(barWidth * (num / 100.0f), barHeight));
            statTexts[i].setString(conver.at(i + 1) + ": " + std::to_string(num));
        }
        subprogress[0].setSize(sf::Vector2f(subWidth * (activebody.stud->physic.value / 100.0f), subHeight));
        subprogress[1].setSize(sf::Vector2f(subWidth * (activebody.stud->math.value / 100.0f), subHeight));
        subprogress[2].setSize(sf::Vector2f(subWidth * (activebody.stud->proga.value / 100.0f), subHeight));

        // Отрисовка
        sf::Vector2u windowSize = window.getSize();
        float coefx = static_cast<float>(windowSize.x) / sizepicture.x;
        float coefy = static_cast<float>(windowSize.y) / sizepicture.y;
        backgroundSprite.setScale(sf::Vector2f(coefx, coefy));
        window.clear(sf::Color(50, 50, 50));
        window.draw(backgroundSprite);
        window.draw(pebutton);
        window.draw(petext);
        window.draw(peuptext);
        window.draw(daybutton);
        window.draw(daytext);
        for (size_t i = 0; i < subnumber.size(); ++i) {
            window.draw(subbackground[i]);
            window.draw(subprogress[i]);
            window.draw(subtexts[i]);
        }
        for (size_t i = 0; i < barsnumber.size(); ++i) {
            window.draw(barbackground[i]);
            window.draw(bartexts[i]);
            window.draw(barprogress[i]);
        }
        for (size_t i = 0; i < buttons.size(); ++i) {
            window.draw(buttons[i]);
            window.draw(buttonTexts[i]);
        }
        for (const auto& statText : statTexts) {
            window.draw(statText);
        }
        if (showTextField) {
            window.draw(questionText);
            window.draw(textField);
            window.draw(inputTextDisplay);
        }
        if (messageTimer > 0) {
            window.draw(statusMessage);
        }
        window.display();
    }