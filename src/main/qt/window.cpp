#include <QApplication>

#include "window.h"

namespace micromouse {
namespace graphics {

Window::Window(QWidget *parent)
  : QWidget(parent) {
  setFixedSize(width_, height_);

  // Set up borders
  leftBorder = new QLine(width_ - borderOffset_,
                         borderOffset_,
                         width_ - borderOffset_,
                         height_ - borderOffset_);

  // Exit button
  exit_ = new QPushButton("Exit", this);
  exit_->setGeometry(width_ - borderOffset_, 0, borderOffset_, borderOffset_);
  QObject::connect(exit_, SIGNAL (released()), QApplication::instance(), SLOT (quit()));

  // Title
  title_ = new QLabel(this);
  title_->move(2 * borderOffset_, 0);
  title_->setTextFormat(Qt::RichText);
  title_->setStyleSheet("font-weight: bold; color: red");
  title_->setFixedHeight(borderOffset_);
  title_->setText("Northeastern Micromouse Simulator");
}

}  // graphics
}  // micromouse

