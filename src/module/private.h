/* SPDX-License-Identifier: LGPL-3.0-or-later */

/*
 * Copyright (C) 2021 Perry Werneck <perry.werneck@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

 // https://stackoverflow.com/questions/9378593/dbuswatch-and-dbustimeout-examples

 #include <config.h>
 #include <udjat/defs.h>
 #include <udjat/tools/dbus.h>
 #include <udjat/alert/abstract.h>
 #include <iostream>
 #include <system_error>

 using namespace std;

 namespace Udjat {

	namespace DBus {

		class Alert : public Udjat::Abstract::Alert {
		private:

			/// @brief The bus type for alert.
			DBusBusType bustype = DBUS_BUS_SESSION;

			/// @brief The path to the object emitting the signal.
			const char *path = nullptr;

			/// @brief The interface the signal is emitted from.
			const char *iface = nullptr;

			/// @brief Name of the signal.
			const char *member = nullptr;

			/// @brief D-Bus message argument.
			struct Argument {
				int type = DBUS_TYPE_INVALID;
				DBusBasicValue value;
				Argument(const Abstract::Object &parent, const char *group, const pugi::xml_node &node);
			};

			/// @brief D-Bus message arguments.
			std::vector<Argument> arguments;

		public:
			Alert(const Abstract::Object &parent, const pugi::xml_node &node);
			virtual ~Alert();

			std::shared_ptr<Udjat::Alert::Activation> ActivationFactory() const override;

		};

	}

 }
