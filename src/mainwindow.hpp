
/*!
	\file

	\author Igor Mironchik (igor.mironchik at gmail dot com).

	Copyright (c) 2023 Igor Mironchik

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// Qt include.
#include <QMainWindow>
#include <QScopedPointer>


namespace MdEditor {

//
// MainWindow
//

struct MainWindowPrivate;

//! Main window.
class MainWindow
	:	public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	~MainWindow() override;

	void openFile( const QString & path );

protected:
	void resizeEvent( QResizeEvent * e ) override;
    void closeEvent( QCloseEvent * e ) override;
	bool event( QEvent * event ) override;

private slots:
    void onFileNew();
    void onFileOpen();
    void onFileSave();
    void onFileSaveAs();
	void onTextChanged();
	void onAbout();
	void onAboutQt();
	void onLineHovered( int lineNumber, const QPoint & pos );
	void onFind( bool on );
	void onGoToLine( bool on );

private:
    bool isModified() const;
	QString htmlContent() const;

private:
	Q_DISABLE_COPY( MainWindow )

	friend struct MainWindowPrivate;

	QScopedPointer< MainWindowPrivate > d;
}; // class MainWindow

} /* namespace MdEditor */
