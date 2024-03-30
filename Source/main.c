#include <stdio.h>
#include <stdlib.h>

static int NumberOfAvailableUnitInYAxis = (int)0;
static int NumberOfAvailableUnitInXAxis = (int)0;

int **Create_CoordinateSystem(int YLength, int XLength);
void Initialize_CoordinateSystem(int **CoordinateSystem, int Shape);
void Show_CoordinateSystem(int **CoordinateSystem);

void Set_Coordinate(int **CoordinateSystem, int YCoordinate, int XCoordinate, int Shape);
void Draw_Coordinate(int **CoordinateSystem, int (*Function)(int), int StartXCoordinate, int EndXCoordinate, int Shape);

int XPower2(int X)
{
    return (X * X);
}

int XIsEqualToY(int X)
{
    return X;
}

int XPlus1(int X)
{
    return (X + (int)1);
}

int main(int argc, const char *argv[])
{
    int **CoordinateSystem;

    CoordinateSystem = Create_CoordinateSystem((int)40, (int)40);

    Initialize_CoordinateSystem(CoordinateSystem, (int)' ');
    Draw_Coordinate(CoordinateSystem, XPower2, 1, 6, '.');
    Show_CoordinateSystem(CoordinateSystem);

    Initialize_CoordinateSystem(CoordinateSystem, (int)' ');
    Draw_Coordinate(CoordinateSystem, XIsEqualToY, 1, 30, '.');
    Show_CoordinateSystem(CoordinateSystem);

    Initialize_CoordinateSystem(CoordinateSystem, (int)' ');
    Draw_Coordinate(CoordinateSystem, XPlus1, 1, 39, '.');
    Show_CoordinateSystem(CoordinateSystem);

    return (int)0;
}

int **Create_CoordinateSystem(int YLength, int XLength)
{
    int **CoordinateSystem = (int **)calloc(YLength, sizeof(int *));

    for (int Counter = (int)0; Counter < YLength; Counter++)
    {
        *(CoordinateSystem + Counter) = (int *)calloc(XLength, sizeof(int));
    }

    NumberOfAvailableUnitInYAxis = YLength;
    NumberOfAvailableUnitInXAxis = XLength;

    return CoordinateSystem;
}

void Initialize_CoordinateSystem(int **CoordinateSystem, int Shape)
{
    for (int YCoordinate = (int)0; YCoordinate < NumberOfAvailableUnitInYAxis; YCoordinate++)
    {
        for (unsigned short int XCoordinate = (unsigned short int)0; XCoordinate < NumberOfAvailableUnitInXAxis; XCoordinate++)
        {
            *(*(CoordinateSystem + (YCoordinate)) + (XCoordinate)) = Shape;
        }
    }
}

void Show_CoordinateSystem(int **CoordinateSystem)
{
    for (int YCoordinate = (int)(NumberOfAvailableUnitInYAxis - (int)1); YCoordinate >= (int)0; YCoordinate--)
    {
        printf("%2d%s", (YCoordinate + (int)1), "\u2502");
        for (unsigned short int XCoordinate = (int)0; XCoordinate < (int)NumberOfAvailableUnitInXAxis; XCoordinate++)
        {
            putchar(CoordinateSystem[YCoordinate][XCoordinate]);
        }
        putchar((int)'\n');
    }

    putchar((int)' ');
    putchar((int)' ');
    printf("%s", "\u2514");
    for (int Counter = 0; Counter < NumberOfAvailableUnitInXAxis; Counter++)
    {
        printf("%s", "\u2500");
    }
    putchar((int)'\n');

    putchar((int)' ');
    putchar((int)' ');
    putchar((int)' ');
    for (int Counter = 0; Counter < NumberOfAvailableUnitInXAxis; Counter++)
    {
        if (Counter == (int)0)
        {
            printf("%d", (Counter + (int)1));
        }
        if (((Counter + (int)2) == NumberOfAvailableUnitInXAxis))
        {
            printf("%d", (Counter + (int)2));
        }
        else
        {
            putchar((int)' ');
        }
    }
    putchar((int)'\n');
}

void Set_Coordinate(int **CoordinateSystem, int YCoordinate, int XCoordinate, int Shape)
{
    if (((YCoordinate == (int)0) || (XCoordinate == (int)0)))
    {
        puts("Error: Index Is Out Of Range.");
        exit(EXIT_FAILURE);
    }
    else
    {
        *(*(CoordinateSystem + (YCoordinate - (int)1)) + (XCoordinate - (int)1)) = Shape;
    }
}

void Draw_Coordinate(int **CoordinateSystem, int (*Function)(int), int StartXCoordinate, int EndXCoordinate, int Shape)
{
    int XCoordinate = (int)0;
    int YCoordinate = (int)0;

    for (int Counter = StartXCoordinate; Counter <= EndXCoordinate; Counter++)
    {
        XCoordinate = Counter;
        YCoordinate = Function(XCoordinate);

        if (((XCoordinate > NumberOfAvailableUnitInXAxis) || (YCoordinate > NumberOfAvailableUnitInYAxis)))
        {
            puts("Error: Index Is Out Of Range.");
            exit(EXIT_FAILURE);
        }
        else
        {
            Set_Coordinate(CoordinateSystem, YCoordinate, XCoordinate, Shape);
        }
    }
}