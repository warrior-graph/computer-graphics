#include <GL/glut.h>
#include <tuple>

using rgb_tuple_t = std::tuple<float, float, float>;

static constexpr uint16_t kWidth = 500;
static constexpr uint16_t kHeigth = 500;
static constexpr rgb_tuple_t kWhiteTuple{1, 1, 1};
static constexpr rgb_tuple_t kBlackTuple{0, 0, 0};
static constexpr rgb_tuple_t kRedTuple{1, 0, 0};
static constexpr rgb_tuple_t kGreenTuple{0, 1, 0};
static constexpr rgb_tuple_t kBlueTuple{0, 0, 1};

/**
 * @brief Function to draw OpenGL Line
 *
 * @param x1 X of first point
 * @param y1 Y of first point
 * @param x2 X of second point
 * @param y2 Y of second point
 * @param color1 Tuple with RGB values for first point
 * @param color2 Tuple with RGB values for second point
 */
void Line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
          rgb_tuple_t color1, rgb_tuple_t color2);

/**
 * @brief Function to draw OpenGL Triangle
 *
 * @param x X of point
 * @param y Y of point
 * @param underside Underside of the triangle
 */
void Triangle(double x, double y, double underside);

/**
 * @brief Function to draw OpenGL Rhombus Poligon
 *
 * @param width Width of outside window
 * @param height Height of outside window
 */
void Rhombus(double width, double height);

/**
 * @brief Function to draw OpenGL Square
 *
 * @param x X of upper left of the square
 * @param y Y of upper left of the square
 * @param side Side size
 */
void Square(double x, double y, double side);

/**
 * @brief Draw all shapes on a glViewport
 *
 */
void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, kHeigth * .5, kWidth * .5, kHeigth * .5);
    Triangle(0, 250, kWidth);

    glViewport(kWidth * .5, kHeigth * .5, kWidth * .5, kHeigth * .5);
    Rhombus(kWidth, kHeigth);

    glScissor(0, 0, kWidth * .5, kHeigth * .5);
    glEnable(GL_SCISSOR_TEST);
    glViewport(0, 0, kWidth * .5, kHeigth * .5);
    glClearColor(std::get<0>(kGreenTuple), std::get<1>(kGreenTuple),
                 std::get<2>(kGreenTuple), 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    Line(250, 0, 250 + kWidth / 3, 250 + kHeigth / 4, kRedTuple, kBlueTuple);
    Line(250 + kWidth / 3, 250 + kHeigth / 4, kWidth / 4, kHeigth / 2.5,
         kBlueTuple, kWhiteTuple);

    glScissor(kWidth * .5, 0, kWidth * .5, kHeigth * .5);
    glEnable(GL_SCISSOR_TEST);
    glViewport(kWidth * .5, 0, kWidth * .5, kHeigth * .5);
    glClearColor(std::get<0>(kWhiteTuple), std::get<1>(kWhiteTuple),
                 std::get<2>(kWhiteTuple), 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    Square(250, 500, 250);

    glFlush();
}

/**
 * @brief Initialize rendering parameters
 *
 */
void Initialize();

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(kWidth, kHeigth);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("First OpenGL Application");
    glutDisplayFunc(Draw);
    Initialize();
    glutMainLoop();

    return 0;
}

void Line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
          rgb_tuple_t color1, rgb_tuple_t color2)
{
    glBegin(GL_LINES);
    glColor3f(std::get<0>(color1), std::get<1>(color1), std::get<2>(color1));
    glVertex2i(x1, y1);
    glColor3f(0.0, 0.0, 1.0);
    glColor3f(std::get<0>(color2), std::get<1>(color2), std::get<2>(color2));
    glVertex2i(x2, y2);
    glEnd();
}

void Triangle(double x, double y, double underside)
{
    glColor3f(std::get<0>(kWhiteTuple), std::get<1>(kWhiteTuple),
              std::get<2>(kWhiteTuple));

    glBegin(GL_TRIANGLES);
    glVertex2d(x, y);
    glVertex2d(x + underside, y);
    glVertex2d(x + underside * .5, y + underside * 0.5);
    glEnd();
}

void Rhombus(double width, double height)
{
    glBegin(GL_POLYGON);
    glColor3f(std::get<0>(kWhiteTuple), std::get<1>(kWhiteTuple),
              std::get<2>(kWhiteTuple));
    glVertex2d(0, height * .5);
    glVertex2d(width * .5, height);
    glVertex2d(width, height * .5);
    glColor3f(std::get<0>(kBlueTuple), std::get<1>(kBlueTuple),
              std::get<2>(kBlueTuple));
    glVertex2d(width * .5, 0);
    glEnd();
}

void Square(double x, double y, double side)
{
    glBegin(GL_POLYGON);
    glColor3f(std::get<0>(kBlackTuple), std::get<1>(kBlackTuple),
              std::get<2>(kBlackTuple));
    glVertex2d(x, y);
    glColor3f(std::get<0>(kGreenTuple), std::get<1>(kGreenTuple),
              std::get<2>(kGreenTuple));
    glVertex2d(x + side, y);
    glColor3f(std::get<0>(kWhiteTuple), std::get<1>(kWhiteTuple),
              std::get<2>(kWhiteTuple));
    glVertex2d(x + side, y - side);
    glColor3f(std::get<0>(kRedTuple), std::get<1>(kRedTuple),
              std::get<2>(kRedTuple));
    glVertex2d(x, y - side);
    glEnd();
}

void Initialize()
{
    glClearColor(std::get<0>(kRedTuple), std::get<1>(kRedTuple),
                 std::get<2>(kRedTuple), 1.0f);

    glOrtho(0, kWidth, 0, kHeigth, -1, 1);
}