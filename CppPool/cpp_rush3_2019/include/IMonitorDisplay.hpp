/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IMonitoreDisplay
*/

#ifndef IMONITOREDISPLAY_HPP_
#define IMONITOREDISPLAY_HPP_

class IMonitorDisplay {
	public:
		virtual ~IMonitorDisplay() {};
        virtual void displayN() = 0;
        virtual void refreshN() = 0;
		//virtual void displayS() const = 0;
        //virtual void refreshS() const = 0;

	protected:
	private:
};

#endif /* !IMONITOREDISPLAY_HPP_ */
