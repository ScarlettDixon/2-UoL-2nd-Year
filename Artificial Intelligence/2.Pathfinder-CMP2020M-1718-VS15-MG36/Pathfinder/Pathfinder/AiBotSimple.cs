using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Audio;
using System.IO;


namespace Pathfinder
{
    class AiBotSimple : AiBotBase
    {
        Random rnd2;
        bool higher = true;
        int XY; //X+ = 1, X- = 2, Y+ = 3, Y- = 4
        public AiBotSimple(int x, int y) : base(x, y) { rnd2 = new Random(); }

        protected override void ChooseNextGridLocation(Level level, Player plr)
        {
            int AiX = GridPosition.X;
            int AiY = GridPosition.Y;
            int PlX = plr.GridPosition.X;
            int PlY = plr.GridPosition.Y;
            int XorY;
            //int TempX;
            //int TempY;

            
            Coord2 newPos;
            newPos = GridPosition;

            if (AiX > PlX)
            {
                if (AiY > PlY)
                {
                    if (AiX > AiY) { newPos.X -= 1; XY = 2; }
                    if (AiX < AiY) { newPos.Y -= 1; XY = 2; }
                    if (AiX == AiY)
                    {
                        XorY = rnd2.Next(0, 2);
                        if (XorY == 0) { newPos.X -= 1; XY = 2; }
                        if (XorY == 1) { newPos.Y -= 1; XY = 4; }
                    }
                }
                if (AiY < PlY)
                {
                    XorY = rnd2.Next(0, 2);
                    if (XorY == 0) { newPos.X -= 1; XY = 2; }
                    if (XorY == 1) { newPos.Y += 1; XY = 3; }
                }
                if (AiY == PlY) { newPos.X -= 1; XY = 2; }

            }
            else if (AiX < PlX)
            {
                if (AiY > PlY)
                {
                    XorY = rnd2.Next(0, 2);
                    if (XorY == 0) { newPos.X += 1; XY = 1; }
                    if (XorY == 1) { newPos.Y -= 1; XY = 4; }

                }
                if (AiY < PlY) {
                    if (AiX > AiY) { newPos.X += 1; XY = 1; }
                    if (AiX < AiY) { newPos.Y += 1; XY = 3; }
                    if (AiX == AiY)
                    {
                        XorY = rnd2.Next(0, 2);
                        if (XorY == 0) { newPos.X += 1; XY = 1; }
                        if (XorY == 1) { newPos.Y += 1; XY = 3; }
                    }
                }
                if (AiY == PlY) { newPos.X += 1; }
            }
            else if (AiX == PlX)
            {
                if (AiY > PlY) { newPos.Y -= 1; XY = 4; }
                if (AiY < PlY) { newPos.Y += 1; XY = 3; }
            }
            if (level.ValidPosition(newPos) == false)
            {
                switch (XY)
                {   //X+ = 1, X- = 2, Y+ = 3, Y- = 4
                    case 1: newPos.X -= 1; newPos.Y -= 1; XY = 4; break;
                    case 2: newPos.X += 1; newPos.Y += 1; XY = 3; break;
                    case 3: newPos.Y -= 1; newPos.X += 1; XY = 1; break;
                    case 4: newPos.Y += 1; newPos.X -= 1; XY = 2; break;
                    default:break;
                }
                SetNextGridPosition(newPos, level);
            }
            SetNextGridPosition(newPos, level);
        //    if (AiX > 0 && AiY > 0) {
        //        higher = true;
        //        XorY(AiX, AiY, higher);
        //    }
        //    if (AiX < 0 && AiY < 0)
        //    {
        //        higher = true;
        //        XorY(AiX, AiY, higher);
        //    }




        }
        //public void XorY(int X, int Y, bool higher) { }



    }
}
