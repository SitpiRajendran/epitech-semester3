--
-- EPITECH PROJECT, 2020
-- FUN_imageCompressor_2019
-- File description:
-- Main
--

import System.Environment
import System.Exit
import System.Random
import Text.Read
import Data.List
----------------------------------------------      ERRORS     ----------------------------------------------

import Error

---------------------------------------------- DATA STRUCTURES ----------------------------------------------

-- Variable Type
type Position = (Int, Int)
type Color = (Int, Int, Int)

-- Strucure Pixel
data Pixel = Pixel {
    pos ::Position,
    pix_color ::Color,
    cluster_id ::Int } deriving (Show)

-- Strucure Cluster
data Cluster = Cluster {
    clust_color :: Color,
    my_id :: Int } deriving (Show)

data Info = Info {
    clust ::[Cluster],
    pix ::[Pixel]}

---------------------------------------------- UTILITIES ----------------------------------------------

error_pixel :: [Pixel] -> IO()
error_pixel [] = putStr ""
error_pixel list = do
    let first = head list
    let posit = pos first
    let x = fst posit
    let colo = pix_color first
    let y = get_first colo
    let new_list = tail list
    case (x,y) of
        (-1,_) -> error_exit "[ERROR] File Parsing"
        (_,-1) -> error_exit "[ERROR] File Parsing"
        _ -> error_pixel new_list

get_num :: String -> Int
get_num text =
    case readMaybe text::Maybe Int of
        Nothing -> -20
        Just x -> x

get_float :: String -> Float
get_float text =
    case readMaybe text::Maybe Float of
        Nothing -> -20
        Just x -> x

get_pos :: String -> Position
get_pos text =
    case readMaybe text::Maybe Position of
        Nothing -> (-1,-1)
        Just x -> x

get_colo :: String -> Color
get_colo text =
    case readMaybe text::Maybe Color of
        Nothing -> (-1,-1,-1)
        Just x -> x

int2float :: Int -> Float
int2float a = fromInteger (toInteger a)::Float

-- Getter from a 3 numbers tupple
get_first:: (Int, Int, Int) -> Int
get_first (a, b, c) = a

get_second:: (Int, Int, Int) -> Int
get_second (a, b, c) = b

get_thrd:: (Int, Int, Int) -> Int
get_thrd (a, b, c) = c

---------------------------------------------- CALCULATING --------------------------------------------

-- Calculate the distance beetween two colors
distance :: (Int, Int, Int) -> (Int, Int, Int) -> Float
distance (xx1, yy1, zz1) (xx2, yy2, zz2) = sqrt (xf*xf + yf*yf + zf*zf)
    where
        x1 = int2float xx1
        x2 = int2float xx2
        y1 = int2float yy1
        y2 = int2float yy2
        z1 = int2float zz1
        z2 = int2float zz2
        xf = x1 - x2
        yf = y1 - y2
        zf = z1 - z2

-- Calculate the average color from a pixel list
average_color:: [Pixel] -> Int -> Int -> Int -> Int -> Color -> Color
average_color [] r_color g_color b_color 0 color = color
average_color [] r_color g_color b_color number color = do
    let new_r = r_color `div` number
    let new_g = g_color `div` number
    let new_b = b_color `div` number
    (new_r, new_g, new_b)
average_color pixel_list r_color g_color b_color number color = do
    let first = head pixel_list
    let the_color = pix_color first
    let new_r = r_color + get_first(the_color)
    let new_g = g_color + get_second(the_color)
    let the_b = get_thrd the_color
    let new_b = b_color + the_b
    let new_pixel_list = tail pixel_list
    average_color new_pixel_list new_r new_g new_b (number + 1) color

-- Verify if it the end of the programm
programm_ending:: [Cluster] -> [Cluster] -> Float -> Bool
programm_ending [] [] convergence = True
programm_ending new_clust old_clust convergence = do
    let new_now = head new_clust
    let old_now = head old_clust
    let new_color = clust_color new_now
    let old_color = clust_color old_now
    let dist = distance new_color old_color
    let calc = dist - convergence
    let new_new = tail new_clust
    let new_old = tail old_clust
    if calc <= 0
        then programm_ending new_new new_old convergence
        else
            False


----------------------------------------------  CREATORS  ----------------------------------------------

-- Create Random Int List
randomlist :: Int -> StdGen ->  [Int]
randomlist n = take n . unfoldr (Just . randomR(1,255))

-- Create Random Cluster List
createClusters:: Int -> [Cluster] -> [Int] -> [Cluster]
createClusters 0 list ran_list = list
createClusters max list ran_list = do
    let r_random = head ran_list
    let new_list = tail ran_list
    let g_random = head new_list
    let new_new_list = tail new_list
    let b_random = head new_new_list
    let for_list = tail new_new_list
    let new_cluster = Cluster (r_random, g_random, b_random) max
    createClusters (max-1) (list ++ [new_cluster]) for_list

-- Create Pixeels List, from a string list
createPixels:: [String] -> [Pixel] -> [Cluster] -> [Pixel]
createPixels [] list clust_list = list
createPixels buffer list clust_list = do
    let first = head buffer
    let word = words first
    let posi = head word
    let posi_num = get_pos posi
    let colo = last word
    let colo_num = get_colo colo
    let wich_clust = get_cluster clust_list colo_num 1000 0
    let new_pixel = Pixel posi_num colo_num wich_clust
    let new_buff = tail buffer
    createPixels new_buff (list ++ [new_pixel]) clust_list

-- Create Average Cluster List
create_newclust:: [Cluster] -> [Pixel] -> [Cluster] -> [Cluster]
create_newclust [] pix_list newclust_list = newclust_list
create_newclust clust_list pix_list newclust_list = do
    let now_clust = head clust_list
    let now_id = my_id now_clust
    let cluster_pixel_list = get_cl2pix now_id pix_list []
    let now_color = clust_color now_clust
    let new_color = average_color cluster_pixel_list 0 0 0 0 now_color
    let clust_list_new = tail clust_list
    let new_clust = Cluster new_color now_id
    create_newclust clust_list_new pix_list (newclust_list ++ [new_clust])

-- Create new pixels with specified clusters from old pixel
create_newpixels:: [Pixel] -> [Cluster] -> [Pixel] -> [Pixel]
create_newpixels [] clust_list new_list = new_list
create_newpixels old_list clust_list new_list = do
    let old_pixel = head old_list
    let posi = pos old_pixel
    let colo = pix_color old_pixel
    let new_clust_id = get_cluster clust_list colo 1000 0
    let new_pix = Pixel posi colo new_clust_id
    let old_old_list = tail old_list
    create_newpixels old_old_list clust_list (new_list ++ [new_pix])

----------------------------------------------   GETTERS  ----------------------------------------------

-- Get the nearest cluster for a specified color
get_cluster:: [Cluster] -> Color -> Float -> Int -> Int
get_cluster [] _ _ d = d
get_cluster a b c d = do
    let now_clust = head a
    let cl_color = clust_color now_clust
    let dist = distance cl_color b
    let new_list = tail a
    if dist <= c
        then get_cluster new_list b (dist) (my_id now_clust)
        else get_cluster new_list b c d

-- Get PixelList of a specified Cluster
get_cl2pix:: Int -> [Pixel] -> [Pixel] -> [Pixel]
get_cl2pix cl_id [] cl_ls = cl_ls
get_cl2pix cl_id list cl_ls = do
    let now_pix = head list
    let pix_id = cluster_id now_pix
    let new_list = tail list
    if (pix_id == cl_id)
        then do
            get_cl2pix cl_id new_list (cl_ls ++ [now_pix])
        else
            get_cl2pix cl_id new_list cl_ls

----------------------------------------------  PRINTERS  ----------------------------------------------

print_cl2pix:: Int -> [Pixel] -> IO()
print_cl2pix cl_id [] = putStr("")
print_cl2pix cl_id list = do
    let now_pix = head list
    let pix_id = cluster_id now_pix
    let new_list = tail list
    if (pix_id == cl_id)
        then do
            putStr $ show (pos now_pix)
            putStr " "
            print (pix_color now_pix)
            print_cl2pix cl_id new_list
        else
            print_cl2pix cl_id new_list

final_print:: [Cluster] -> [Pixel] -> IO()
final_print [] pixel_list = putStr("")
final_print clust_list pixel_list = do
    let now_clust = head clust_list
    let now_id = my_id now_clust
    putStrLn("--")
    print(clust_color now_clust)
    putStrLn("-")
    print_cl2pix now_id pixel_list
    let new_clust_list = tail clust_list
    final_print new_clust_list pixel_list

----------------------------------------------  PROGRAMM  ----------------------------------------------

kmeans_algo:: Info -> Float -> Info
kmeans_algo all convergence = do
    let cluster_list = clust all
    let pixel_list = pix all
    let new_cluster_list = create_newclust cluster_list pixel_list []
    let new_pixel_list = create_newpixels pixel_list new_cluster_list []
    let ret_value = Info new_cluster_list new_pixel_list
    let is_end = programm_ending new_cluster_list cluster_list convergence
    let new_all = Info new_cluster_list new_pixel_list
    if is_end == True
        then ret_value
        else kmeans_algo new_all convergence


launchRead:: [String] -> IO()
launchRead [n_text, e_text, path] = do
    seed <- newStdGen
    let n = get_num n_text
    let e = get_float e_text
    error_handle n e
    let list_cluster = randomlist (n*3) seed
    let clusters = createClusters n [] list_cluster
    contents <- readFile path
    let eachlines = lines contents
    let pixels = createPixels eachlines [] clusters
    error_pixel pixels
    error_cluster (length pixels) n
    let recov = Info clusters pixels
    let organized = kmeans_algo recov e
    let final_clust = clust organized
    let final_pix = pix organized
    final_print final_clust final_pix

main = do
    args <- getArgs
    case args of
        [] -> do
            putStrLn "USAGE: ./imageCompressor n e IN"
            putStrLn "\n\tn\tnumber of colors in the final image"
            putStrLn "\te\t convergence limit"
            putStrLn "\tIN\t path to the file containing the colors of the pixels"
            exitWith (ExitFailure 84)
        _ ->
            case length args of
                3 ->
                    launchRead args
                _ ->
                    error_exit "[ERROR] Bad Numbers Arguments"