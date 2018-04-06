#include "Mouse.h"
#include "DxLib.h"
#include "Manager.h"
#include <limits.h>

MousePtr Mouse::getTask( ) {
	return std::dynamic_pointer_cast< Mouse >( Manager::getInstance( )->getTask( getTag( ) ) );
}

std::string Mouse::getTag( ) {
	return "MOUSE_EVENT";
}

Mouse::Mouse( ) {
	initialize( );
}

Mouse::~Mouse( ) {
}

void Mouse::initialize( ) {
	_mouse = NULL;
	_click_left = 0;
	_click_right = 0;
	_x = 0;
	_y = 0;
	_clickup_left = false;
	_clickup_right = false;
}

void Mouse::finalize( ) {
}

void Mouse::update( ) {
	_clickup_left = false;
	_clickup_right = false;
	_mouse = GetMouseInput( );
	calcLeftClick( );
	calcRightClick( );
	GetMousePoint( &_x, &_y );
}

void Mouse::calcLeftClick( ) {
	if ( _mouse & MOUSE_INPUT_LEFT ) {
		_click_left = ( _click_left + 1 ) % INT_MAX;
		return;
	}

	//�������u�Ԃ����m
	if ( _click_left != 0 ) {
		_clickup_left = true;
	}
	_click_left = 0;
}

void Mouse::calcRightClick( ) {
	if ( _mouse & MOUSE_INPUT_RIGHT ) {
		_click_right = ( _click_right + 1 ) % INT_MAX;
		return;
	}

	//�������u�Ԃ����m
	if ( _click_right != 0 ) {
		_clickup_right = true;
	}
	_click_right = 0;
}

int Mouse::getPointX( ) const {
	return _x;
}

int Mouse::getPointY( ) const {
	return _y;
}

bool Mouse::isClickLeft( ) const {
	if ( _click_left == 1 ) {
		return true;
	}
	return false;
}

bool Mouse::isClickRight( ) const {
	if ( _click_right == 1 ) {
		return true;
	}
	return false;
}

bool Mouse::isClickUpLeft( ) const {
	return _clickup_left;
}

bool Mouse::isClickUpRight( ) const {
	return _clickup_right;
}

int Mouse::getClickingLeft( ) const {
	return _click_left;
}

int Mouse::getClickingRight( ) const {
	return _click_right;
}