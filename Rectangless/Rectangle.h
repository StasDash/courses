#ifndef FIGURES_RECTANGLE_H
#define FIGURES_RECTANGLE_H

#include <algorithm>
#include <optional>
#include <iostream>

namespace figures {
	class Rectangle {
	private:
		double left, top, right, bottom;
	public:
		Rectangle() = delete;
		Rectangle(double left = 0, double top = 0, double right = 0, double bottom = 0) :
			left(std::min(left, right)),
			top(std::max(top, bottom)),
			right(std::max(right, left)),
			bottom(std::min(bottom, top)) {}

		Rectangle BBox(const Rectangle& other) const {
			auto ret = Rectangle(std::min(left, other.left), std::max(top, other.top), std::max(right, other.right), std::min(bottom, other.bottom));
			return ret;
		}

		static std::optional<Rectangle> Intersect(const Rectangle& a, const Rectangle& b) {
			double left = std::max(a.left, b.left);
			double top = std::min(a.top, b.top);
			double right = std::min(a.right, b.right);
			double bottom = std::max(a.bottom, b.bottom);
			if (right - left > 0 && top - bottom > 0) {
				return std::optional(Rectangle(left, top, right, bottom));
			}
			return std::nullopt;
		}

		const Rectangle& operator=(const Rectangle& other) {
			if (this == &other) {
				return *this;
			}

			*this = other;
			return *this;
		}

		bool operator==(const Rectangle& other) const {
			if (left == other.left && right == other.right && top == other.top && bottom == other.bottom) {
				return true;
			}
			return false;
		}

		friend std::ostream& operator<<(std::ostream& cout, const Rectangle& rrect) {
			cout << "Horizontal: left: " << rrect.left << "\tright: " << rrect.right << "\nVertical: top: " << rrect.top << "\tbottom: " << rrect.bottom;
			return cout;
		}

		friend std::ostream& operator<<(std::ostream& cout, const std::optional<Rectangle>& rect) {
			if (!rect.has_value()) {
				cout << "No such rectangle";
			}
			else {
				const auto& rrect = rect.value();
				cout << rrect;
			}
			return cout;
		}
	};
}

#endif