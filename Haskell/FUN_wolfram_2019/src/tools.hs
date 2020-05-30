--
-- EPITECH PROJECT, 2020
-- FUN_wolfram_2019
-- File description:
-- tools
--

module Tools where

createFirst:: Int -> [Char]
createFirst window
    | window `mod` 2 == 0 = [' ' | window <- [0..(window`div`2)-1]] ++ "*" ++[' ' | window <- [0..(window`div`2)-2]]
    | otherwise = [' ' | window <- [0..(window`div`2)-1]] ++ "*" ++[' ' | window <- [0..(window`div`2)-1]]

printline:: Int -> Int -> [Char] -> IO()
printline num start line
    | start <= 1 && num >= 1 = putStrLn line
    | otherwise = putStr ""
