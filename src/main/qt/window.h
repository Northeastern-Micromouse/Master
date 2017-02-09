#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

namespace micromouse {
namespace graphics {


class Window : public QWidget {
  Q_OBJECT
 public:
  explicit Window(QWidget *parent = 0);

 private:
  int width_ = 530;
  int height_ = 530;

  QPainter* painter_;

  // Borders
  int borderOffset_ = 50;
  QLine* rightBorder;
  QLine* leftBorder;
  QLine* topBorder;
  QLine* bottomBorder;

  // Exit
  QPushButton* exit_;

  // Title
  QLabel* title_;

 signals:

 public slots:
};

}
}

#endif  // WINDOW_H
