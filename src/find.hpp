
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
#include <QFrame>
#include <QScopedPointer>


namespace MdEditor {

//
// Find
//

struct FindPrivate;
class Editor;

//! Find/replace widget.
class Find
	:	public QFrame
{
	Q_OBJECT

public:
	Find( Editor * editor, QWidget * parent );
	~Find() override;

public slots:
	void setFindText( const QString & text );
	void setFocusOnFind();

private slots:
	void onFindTextChanged( const QString & str );
	void onReplaceTextChanged( const QString & str );
	void onReplace();
	void onReplaceAll();
	void onSelectionChanged();

private:
	friend struct FindPrivate;

	Q_DISABLE_COPY( Find )

	QScopedPointer< FindPrivate > d;
}; // class Find

} /* namespace MdEditor */
