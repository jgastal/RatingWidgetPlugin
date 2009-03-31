#ifndef RATINGWIDGET_H
#define RATINGWIDGET_H

#include <QWidget>
#include <QDesignerCustomWidgetInterface>

class QToolButton;
class QIcon;

class RatingWidget : public QWidget
{
	Q_OBJECT

	public:
		RatingWidget(QWidget *parent = 0, int count = 5);
		virtual ~RatingWidget();

	private:
		QToolButton *starButton;
		QIcon *emptyIcon, *fullIcon;
		int max;

	private slots:
		void setRating();
};

#endif // RATINGWIDGET_H
