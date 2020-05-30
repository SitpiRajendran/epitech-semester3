module Error
    ( error_exit, error_handle, error_cluster
    ) where

import System.Environment
import System.Exit

error_exit :: String -> IO()
error_exit text = do
    putStrLn text
    exitWith (ExitFailure 84)

error_handle :: Int -> Float -> IO()
error_handle n e
    | n >= 1 && e >= 0 = putStr ""
    | otherwise = error_exit "[ERROR] Number of Cluster or Convergence error"

error_cluster :: Int -> Int -> IO()
error_cluster pixel_num clust_num
    | clust_num <= pixel_num = putStr ""
    | otherwise = error_exit "[ERROR] Cluster number error"
