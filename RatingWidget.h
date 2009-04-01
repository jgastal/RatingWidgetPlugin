#ifndef RATINGWIDGET_H
#define RATINGWIDGET_H

#include <QWidget>
#include <QDesignerCustomWidgetInterface>

class QToolButton;
class QIcon;
class QHBoxLayout;

class RatingWidget : public QWidget
{
	Q_OBJECT

	Q_PROPERTY(int max READ getMax WRITE setMax DESIGNABLE true)

	public:
		RatingWidget(QWidget *parent = 0, int count = 5);
		virtual ~RatingWidget();
		int getMax() const;
		void setMax(int count);
		int getValue() const;

	private:
		void initButton(QToolButton *bt);
		QToolButton *starButton;
		QIcon *emptyIcon, *fullIcon;
		QHBoxLayout *layout;
		int max;

	private slots:
		void setRating();
};

#endif // RATINGWIDGET_H
