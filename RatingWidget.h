#ifndef RATINGWIDGET_H
#define RATINGWIDGET_H

#include <QWidget>

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
		int getRating() const;

	public slots:
		void setRating(int r);

	private:
		void initButton(QToolButton *bt);
		QToolButton *starButton;
		QIcon *emptyIcon, *fullIcon;
		QHBoxLayout *layout;
		int max;
		int rating;

	private slots:
		void setRating();
};

#endif // RATINGWIDGET_H
