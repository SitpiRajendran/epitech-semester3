/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** ErrorHandling
*/

#ifndef __ERRORHANDLING__
#define __ERRORHANDLING__

namespace indie {
    class ErrorHandling {
        public:
            ErrorHandling();
            ~ErrorHandling();

            bool env_handling(char **env);

        private:
    };
}

#endif