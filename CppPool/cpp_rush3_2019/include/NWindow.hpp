/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** NWindow
*/

#ifndef NWINDOW_HPP_
#define NWINDOW_HPP_

#include <iostream>
#include <vector>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class NWindow {
	public:
		NWindow();
		~NWindow();
        int getHeight() const;
        int getLenght() const;
        const std::vector<IMonitorModule *> &getModule() const;
        const std::vector<IMonitorDisplay *> &getDisplay() const;
        void setHeight(int height);
        void setLenght(int lenght);
        void addModule(IMonitorModule &module, IMonitorDisplay &display);
        void addDispay(IMonitorDisplay &module);
        void addAllModule();
        std::vector<IMonitorModule *> _modules;
        std::vector<IMonitorDisplay *> _display;

	protected:
        int _height;
        int _lenght;

	private:
};

#endif /* !NWINDOW_HPP_ */
