/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

enum KEY {
    z,
    q,
    s,
    d,
    p,
    UP,
    DOWN,
    RIGHT,
    LEFT,
    SPACE,
    ENTER,

}
class IDisplay {
    public:
        IDisplay();
        ~IDisplay();
        key get_key();
    private:
};

#endif /* !IDISPLAY_HPP_ */
