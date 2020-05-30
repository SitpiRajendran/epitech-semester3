/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IMonitorModule
*/

#ifndef __IMONITORMODULE_HPP__
#define __IMONITORMODULE_HPP__

class IMonitorModule {
	public:
		virtual ~IMonitorModule() {};
		virtual const std::string &getName() const = 0;
        virtual const std::string &getValue() = 0;
};

#endif