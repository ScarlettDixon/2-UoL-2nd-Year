using System;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Audio;
using System.IO;

namespace Pathfinder
{
    class Dijkstra
    {
        public bool[,] closed; //whether or not location is closed
        public float[,] cost; //cost value for each location
        public Coord2[,] link; //link for each location = coords of a neighbouring location
        public bool[,] inPath; //whether or not a location is in the final path
        public float LowestVal;
        public int LowestX;
        public int LowestY;
        public int count = 0;
        public bool dijk_Activate = true;
        //public int[,] Lowest;
        public Dijkstra()
        {
            closed = new bool[40, 40];
            cost = new float[40, 40];
            link = new Coord2[40, 40];
            inPath = new bool[40, 40];
            //Lowest = new int[40, 40];
            
        }

        public void build(Level level, AiBotBase bot, Player plr)
        {
            for (int i = 0; i < 40; i++)
            {
                for (int j = 0; j < 40; j++)
                {
                    closed[i, j] = false;
                    cost[i, j] = 10000000000;
                    link[i, j].Equals(new Coord2(-1, -1));
                    inPath[i, j] = false;
                }

            }
            closed[bot.GridPosition.X, bot.GridPosition.Y] = false;
            cost[bot.GridPosition.X, bot.GridPosition.Y] = 0;
            LowestVal = 10000000000;
            while (closed[plr.GridPosition.X, plr.GridPosition.Y] == false)
            {
                LowestVal = 10000000000;
                for (int i = 0; i < 40; i++)
                {
                    for (int j = 0; j < 40; j++)
                    {
                        if (LowestVal > cost[i, j] && closed[i, j] == false && level.ValidPosition(new Coord2(i, j)) == true)
                        {
                            LowestVal = cost[i, j];
                            LowestX = i;
                            LowestY = j;
                        }


                    }
                }

                closed[LowestX, LowestY] = true;
                count = 0;
                for (int i = LowestX -1; i <= LowestX+1; i++) {
                    for (int j = LowestY - 1; j <= LowestY+1; j++ ) {
                        if ((i != LowestX || j != LowestY) && level.ValidPosition(new Coord2(i, j))== true)
                        {
                            switch (count)
                            {
                                case (0): case (2): case (6): case (8):
                                    if ((LowestVal + 1.4f) < cost[i, j]) {
                                        cost[i, j] = LowestVal + 1.4f;
                                        link[i, j] = new Coord2(LowestX, LowestY);
                                    }
                                    break;

                                case (1): case (3): case (5): case (7):
                                    if ((LowestVal + 1.0f) < cost[i, j]) {
                                        cost[i, j] = LowestVal + 1.0f;
                                        link[i, j] = new Coord2(LowestX, LowestY);
                                    }
                                    break;
                                default: break;
                            }
                            
                        }
                        count++;
                    }
                }
            }
            bool done = false; //set to true when we are back at the bot position
            Coord2 nextClose = plr.GridPosition; //start of path
            while (!done)
            {
                inPath[nextClose.X, nextClose.Y] = true;
                nextClose = link[nextClose.X, nextClose.Y];
                //Console.WriteLine("X = {0}, Y = {1}", nextClose.X, nextClose.Y);
                if (nextClose == bot.GridPosition) { done = true; }
            }
           

        }
    }
}
