#include "aboutwindow.h"
#include <QVBoxLayout>

AboutWindow::AboutWindow(QWidget *parent)
    : QMainWindow{parent}
{
    QWidget *centralWindget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    setCentralWidget(centralWindget);
    centralWindget->setLayout(layout);

    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    textEdit->setAlignment(Qt::AlignCenter);
    textEdit->setFontPointSize(16);
    textEdit->setStyleSheet("border: 0; background-color: transparent;");
    textEdit->setText("Anime Go is the application where you can find various of new for yourself anime. User can sort and filter the results in order to find what he needs and get detailed information about chosen anime.");
    setFixedSize(400, 400);

    QSpacerItem* spacer = new QSpacerItem(50, 250, QSizePolicy::Fixed, QSizePolicy::Fixed);
    layout->addSpacerItem(spacer);
    layout->addWidget(textEdit);

}


void AboutWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    QLinearGradient gradientBack(rect().topLeft(), rect().bottomRight());
    gradientBack.setColorAt(0, QColor(255, 255, 255));   // Start color
    gradientBack.setColorAt(1, QColor(255, 200, 0));     // End color
    painter.fillRect(rect(), gradientBack);

    //center position for the circle
    int centerX = width() / 2;
    int centerY = height() / 2 - 50;

    QRadialGradient gradient(centerX, centerY, 100, centerX, centerY);
    gradient.setColorAt(0, QColor(255, 0, 0));        // Red
    gradient.setColorAt(1, QColor(200, 0, 0));        // Darker red

    QPen pen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QBrush brush(gradient);

    // Draw the outer circle
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(centerX - 100, centerY - 100, 200, 200);

    // Draw the inner circle
    painter.setBrush(Qt::NoBrush);
    painter.drawEllipse(centerX - 60, centerY - 60, 120, 120);

    painter.setBrush(Qt::black);
    painter.drawEllipse(centerX - 80, centerY + 15, 40, 40);

    painter.drawEllipse(centerX + 45, centerY + 15, 40, 40);

    painter.drawEllipse(centerX - 20, centerY - 90, 40, 40);

    // Draw the letter "A" inside the inner circle
    QFont font("Arial", 80, QFont::Bold);
    QFontMetrics fontMetrics(font);
    int textWidth = fontMetrics.horizontalAdvance("A");
    int textHeight = fontMetrics.height();
    int textX = centerX - textWidth / 2;
    int textY = centerY + textHeight / 2 - 15;
    painter.setFont(font);
    painter.drawText(textX, textY, "A");
}
