/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef BASE_NOTIFICATION_ANS_STANDARD_FRAMEWORKS_ANS_CORE_INCLUDE_ANS_NOTIFICATION_H
#define BASE_NOTIFICATION_ANS_STANDARD_FRAMEWORKS_ANS_CORE_INCLUDE_ANS_NOTIFICATION_H

#include <list>

#include "ans_manager_death_recipient.h"
#include "ans_manager_interface.h"
#include "notification_subscriber.h"

namespace OHOS {
namespace Notification {
class AnsNotification {
public:
    /**
     * @brief Creates a notification slot.
     * @note You can call the NotificationRequest::SetSlotType(NotificationConstant::SlotType) method to bind the slot
     * for publishing. A NotificationSlot instance cannot be used directly after being initialized. Instead, you have to
     * call this method to create a notification slot and bind the slot ID to a NotificationRequest object so that the
     * notification published can have all the characteristics set in the NotificationSlot. After a notification slot is
     * created by using this method, only the name and description of the notification slot can be changed. Changes to
     * the other attributes, such as the vibration status and notification tone, will no longer take effect.
     *
     * @param slot Indicates the notification slot to be created, which is set by NotificationSlot.
     *             This parameter must be specified.
     * @return Returns add notification slot result.
     */
    ErrCode AddNotificationSlot(const NotificationSlot &slot);

    /**
     * @brief Adds a notification slot by type.
     *
     * @param slotType Indicates the notification slot type to be added.
     * @return Returns add notification slot result.
     */
    ErrCode AddSlotByType(const NotificationConstant::SlotType &slotType);

    /**
     * @brief Creates multiple notification slots.
     *
     * @param slots Indicates the notification slots to create.
     * @return Returns add notification slots result.
     */
    ErrCode AddNotificationSlots(const std::vector<NotificationSlot> &slots);

    /**
     * @brief Deletes a created notification slot based on the slot ID.
     *
     * @param slotType Indicates the ID of the slot, which is created by AddNotificationSlot
     *                This parameter must be specified.
     * @return Returns remove notification slot result.
     */
    ErrCode RemoveNotificationSlot(const NotificationConstant::SlotType &slotType);

    /**
     * @brief Deletes all notification slots.
     *
     * @return Returns remove all slots result.
     */
    ErrCode RemoveAllSlots();

    /**
     * @brief Queries a created notification slot.
     *
     * @param slotType Indicates the ID of the slot, which is created by AddNotificationSlot(NotificationSlot). This
     *        parameter must be specified.
     * @param slot Indicates the created NotificationSlot.
     * @return Returns the get notification slot result.
     */
    ErrCode GetNotificationSlot(const NotificationConstant::SlotType &slotType, sptr<NotificationSlot> &slot);

    /**
     * @brief Obtains all notification slots of this application.
     *
     * @param slots Indicates the created NotificationSlot.
     * @return Returns all notification slots of this application.
     */
    ErrCode GetNotificationSlots(std::vector<sptr<NotificationSlot>> &slots);

    /**
     * @brief Creates a notification slot group to which a NotificationSlot object can be bound by
     * calling NotificationSlot::SetSlotGroup(string).
     * @note  A NotificationSlotGroup instance cannot be used directly after being initialized.
     *        Instead, you have to call this method to create a notification slot group so that you can bind
     *        NotificationSlot objects to it.
     *
     * @param slotGroup Indicates the notification slot group to be created, which is set by NotificationSlotGroup.
     *                  This parameter must be specified. the notification slot to be created, which is set by
     *                  NotificationSlot.
     * @return Returns add notification slot group result.
     */
    ErrCode AddNotificationSlotGroup(const NotificationSlotGroup &slotGroup);

    /**
     * @brief Creates multiple notification slot groups.
     * @note The precautions for using this method are similar to those for
     * AddNotificationSlotGroup(NotificationSlotGroup).
     *
     * @param slotGroups Indicates a list of NotificationSlotGroup objects to create. This parameter cannot be null.
     * @return Returns add notification slot groups result.
     */
    ErrCode AddNotificationSlotGroups(const std::vector<NotificationSlotGroup> &slotGroups);

    /**
     * @brief Deletes a created notification slot group based on the slot group ID.
     *
     * @param slotGroupId  Indicates the ID of the notification slot group, which is created by
     *                     AddNotificationSlotGroup(NotificationSlotGroup) This parameter must be specified.
     * @return Returns remove notification slot group result.
     */
    ErrCode RemoveNotificationSlotGroup(const std::string &slotGroupId);

    /**
     * @brief Queries a created notification slot group.
     *
     * @param  groupId Indicates the ID of the slot group.
     * @param  group   Indicates the created NotificationSlotGroup.
     * @return Returns get notification slot group result.
     */
    ErrCode GetNotificationSlotGroup(const std::string &groupId, sptr<NotificationSlotGroup> &group);

    /**
     * @brief Obtains a list of created notification slot groups.
     *
     * @param  groups Indicates a list of created notification slot groups.
     * @return Returns get notification slot groups result.
     */
    ErrCode GetNotificationSlotGroups(std::vector<sptr<NotificationSlotGroup>> &groups);

    /**
     * @brief Obtains number of slot.
     *
     * @param bundleOption Indicates the bundle name and uid of the application.
     * @param num Indicates number of slot.
     * @return Returns get slot number by bundle result.
     */
    ErrCode GetNotificationSlotNumAsBundle(const NotificationBundleOption &bundleOption, uint64_t &num);

    /**
     * @brief Publishes a notification.
     * @note If a notification with the same ID has been published by the current application and has not been deleted,
     * this method will update the notification.
     *
     * @param request Indicates the NotificationRequest object for setting the notification content.
     *                This parameter must be specified.
     * @return Returns publish notification result.
     */
    ErrCode PublishNotification(const NotificationRequest &request);

    /**
     * @brief Publishes a notification with a specified label.
     * @note If a notification with the same ID has been published by the current application and has not been deleted,
     *       this method will update the notification.
     *
     * @param label Indicates the label of the notification to publish.
     * @param request Indicates the NotificationRequest object for setting the notification content.
     *                This parameter must be specified.
     * @return Returns publish notification result.
     */
    ErrCode PublishNotification(const std::string &label, const NotificationRequest &request);

    /**
     * @brief Publishes a notification on a specified remote device.
     * @note If a notification with the same ID has been published by the current application and has not been deleted,
     *       this method will update the notification.
     *
     * @param request Indicates the NotificationRequest object for setting the notification content.
     *                This parameter must be specified.
     * @param deviceId Indicates the ID of the remote device. If this parameter is null or an empty string,
     *                 the notification will be published on the local device.
     * @return Returns publish notification result.
     */
    ErrCode PublishNotification(const NotificationRequest &request, const std::string &deviceId);

    /**
     * @brief Cancels a published notification.
     *
     * @param notificationId Indicates the unique notification ID in the application.
     *                       The value must be the ID of a published notification.
     *                       Otherwise, this method does not take effect.
     * @return Returns cancel notification result.
     */
    ErrCode CancelNotification(int32_t notificationId);

    /**
     * @brief Cancels a published notification matching the specified label and notificationId.
     *
     * @param label Indicates the label of the notification to cancel.
     * @param notificationId Indicates the ID of the notification to cancel.
     * @return Returns cancel notification result.
     */
    ErrCode CancelNotification(const std::string &label, int32_t notificationId);

    /**
     * @brief Cancels all the published notifications.
     * @note To cancel a specified notification, see CancelNotification(int_32).
     *
     * @return Returns cancel all notifications result.
     */
    ErrCode CancelAllNotifications();

    /**
     * @brief Cancels a published agent notification.
     *
     * @param notificationId Indicates the unique notification ID in the application.
     *                       The value must be the ID of a published notification.
     *                       Otherwise, this method does not take effect.
     * @param representativeBundle Indicates the name of application bundle your application is representing.
     * @param userId Indicates the specific user.
     * @return Returns cancel notification result.
     */
    ErrCode CancelAsBundle(int32_t notificationId, const std::string &representativeBundle, int32_t userId);

    /**
     * @brief Obtains the number of active notifications of the current application in the system.
     *
     * @param num Indicates the number of active notifications of the current application.
     * @return Returns get active notification nums result.
     */
    ErrCode GetActiveNotificationNums(uint64_t &num);

    /**
     * @brief Obtains active notifications of the current application in the system.
     *
     * @param  request Indicates active NotificationRequest objects of the current application.
     * @return Returns get active notifications result.
     */
    ErrCode GetActiveNotifications(std::vector<sptr<NotificationRequest>> &request);

    /**
     * @brief Obtains the map for sorting notifications of the current application.
     *
     * @param sortingMap Indicates the NotificationSortingMap object for the current application.
     * @return Returns get current app sorting result.
     */
    ErrCode GetCurrentAppSorting(sptr<NotificationSortingMap> &sortingMap);

    /**
     * @brief Allows another application to act as an agent to publish notifications in the name of your application
     * bundle. You can revoke this authorization by passing null to this method.
     *
     * @param agent Indicates the name of the application bundle that can publish notifications for your application.
     * @return Returns set notification agent result.
     */
    ErrCode SetNotificationAgent(const std::string &agent);

    /**
     * @brief Obtains the name of the application bundle that can publish notifications in the name of your application.
     *
     * @param agent Indicates the name of the application bundle that can publish notifications for your application if
     * any; returns null otherwise.
     * @return Returns get notification agent result.
     */
    ErrCode GetNotificationAgent(std::string &agent);

    /**
     * @brief Checks whether your application has permission to publish notifications by calling
     * PublishNotificationAsBundle(string, NotificationRequest) in the name of another application indicated by the
     * given representativeBundle.
     *
     * @param representativeBundle Indicates the name of application bundle your application is representing.
     * @param canPublish Indicates whether your application has permission to publish notifications.
     * @return Returns can publish notification as bundle result.
     */
    ErrCode CanPublishNotificationAsBundle(const std::string &representativeBundle, bool &canPublish);

    /**
     * @brief Publishes a notification in the name of a specified application bundle.
     * @note If the notification to be published has the same ID as a published notification that has not been canceled,
     * the existing notification will be replaced by the new one.
     *
     * @param request Indicates the NotificationRequest object for setting the notification content.
     *                This parameter must be specified.
     * @param representativeBundle Indicates the name of the application bundle that allows your application to publish
     *                             notifications for it by calling setNotificationAgent.
     * @return Returns publish notification as bundle result.
     */
    ErrCode PublishNotificationAsBundle(const std::string &representativeBundle, const NotificationRequest &request);

    /**
     * @brief Sets the number of active notifications of the current application as the number to be displayed on the
     * notification badge.
     *
     * @return Returns set notification badge num result.
     */
    ErrCode SetNotificationBadgeNum();

    /**
     * @brief Sets the number to be displayed on the notification badge of the application.
     *
     * @param num Indicates the number to display. A negative number indicates that the badge setting remains unchanged.
     *            The value 0 indicates that no badge is displayed on the application icon.
     *            If the value is greater than 99, 99+ will be displayed.
     * @return Returns set notification badge num result.
     */
    ErrCode SetNotificationBadgeNum(int32_t num);

    /**
     * @brief Checks whether this application has permission to publish notifications. The caller must have
     * system permissions to call this method.
     *
     * @param  allowed True if this application has the permission; returns false otherwise
     * @return Returns is allowed notify result.
     */
    ErrCode IsAllowedNotify(bool &allowed);

    /**
     * @brief Checks whether this application has permission to publish notifications.
     *
     * @param  allowed True if this application has the permission; returns false otherwise
     * @return Returns is allowed notify result.
     */
    ErrCode IsAllowedNotifySelf(bool &allowed);

    /**
     * @brief Allows the current application to publish notifications on a specified device.
     *
     * @param deviceId Indicates the ID of the device running the application. At present, this parameter can
     *                 only be null or an empty string, indicating the current device.
     * @return Returns set notifications enabled for default bundle result.
     */
    ErrCode RequestEnableNotification(std::string &deviceId);

    /**
     * @brief Checks whether this application is in the suspended state.Applications in this state cannot publish
     * notifications.
     *
     * @param suspended True if this application is suspended; returns false otherwise.
     * @return Returns are notifications suspended.
     */
    ErrCode AreNotificationsSuspended(bool &suspended);

    /**
     * @brief Checks whether this application has permission to modify the Do Not Disturb (DND) notification policy.
     *
     * @param hasPermission True if this application is suspended; returns false otherwise.
     * @return Returns has notification policy access permission.
     */
    ErrCode HasNotificationPolicyAccessPermission(bool &hasPermission);

    /**
     * @brief Obtains the importance level of this application.
     *
     * @param  importance the importance level of this application, which can be LEVEL_NONE,
               LEVEL_MIN, LEVEL_LOW, LEVEL_DEFAULT, LEVEL_HIGH, or LEVEL_UNDEFINED.
     * @return Returns get bundle importance result
     */
    ErrCode GetBundleImportance(NotificationSlot::NotificationLevel &importance);

    /**
     * @brief Subscribes to notifications from all applications. This method can be called only by applications
     * with required system permissions.
     * @note  To subscribe to a notification, inherit the {NotificationSubscriber} class, override its
     *        callback methods and create a subscriber. The subscriber will be used as a parameter of this method.
     *        After the notification is published, subscribers that meet the filter criteria can receive the
     * notification. To subscribe to notifications published only by specified sources, for example, notifications from
     *        certain applications, call the {SubscribeNotification(NotificationSubscriber, NotificationSubscribeInfo)}
     * method.
     *
     * @param subscriber Indicates the {NotificationSubscriber} to receive notifications.
     *                   This parameter must be specified.
     * @return Returns subscribe notification result.
     */
    ErrCode SubscribeNotification(const NotificationSubscriber &subscriber);

    /**
     * @brief Subscribes to all notifications based on the filtering criteria. This method can be called only
     * by applications with required system permissions.
     * @note  After {subscribeInfo} is specified, a subscriber receives only the notifications that
     *        meet the filter criteria specified by {subscribeInfo}.
     *        To subscribe to a notification, inherit the {NotificationSubscriber} class, override its
     *        callback methods and create a subscriber. The subscriber will be used as a parameter of this method.
     *        After the notification is published, subscribers that meet the filter criteria can receive the
     * notification. To subscribe to and receive all notifications, call the
     * {SubscribeNotification(NotificationSubscriber)} method.
     *
     * @param subscriber Indicates the subscribers to receive notifications. This parameter must be specified.
     *                   For details, see {NotificationSubscriber}.
     * @param subscribeInfo Indicates the filters for specified notification sources, including application name,
     *                      user ID, or device name. This parameter is optional.
     * @return Returns subscribe notification result.
     */
    ErrCode SubscribeNotification(
        const NotificationSubscriber &subscriber, const NotificationSubscribeInfo &subscribeInfo);

    /**
     * @brief Unsubscribes from all notifications. This method can be called only by applications with required
     * system permissions.
     * @note Generally, you subscribe to a notification by calling the
     *       {SubscribeNotification(NotificationSubscriber)} method. If you do not want your application
     *       to receive a notification any longer, unsubscribe from that notification using this method.
     *       You can unsubscribe from only those notifications that your application has subscribed to.
     *        To unsubscribe from notifications published only by specified sources, for example,
     *       notifications from certain applications, call the
     *       {UnSubscribeNotification(NotificationSubscriber, NotificationSubscribeInfo)} method.
     *
     * @param subscriber Indicates the {NotificationSubscriber} to receive notifications.
     *                   This parameter must be specified.
     * @return Returns unsubscribe notification result.
     */
    ErrCode UnSubscribeNotification(NotificationSubscriber &subscriber);

    /**
     * @brief Unsubscribes from all notifications based on the filtering criteria. This method can be called
     * only by applications with required system permissions.
     * @note A subscriber will no longer receive the notifications from specified notification sources.
     *
     * @param subscriber Indicates the {NotificationSubscriber} to receive notifications.
     *                   This parameter must be specified.
     * @param subscribeInfo Indicates the filters for , including application name,
     *                      user ID, or device name. This parameter is optional.
     * @return Returns unsubscribe notification result.
     */
    ErrCode UnSubscribeNotification(NotificationSubscriber &subscriber, NotificationSubscribeInfo subscribeInfo);

    /**
     * @brief Removes a specified removable notification of other applications.
     * @note Your application must have platform signature to use this method.
     *
     * @param key Indicates the key of the notification to remove.
     * @return Returns remove notification result.
     */
    ErrCode RemoveNotification(const std::string &key);

    /**
     * @brief Removes a specified removable notification of other applications.
     * @note Your application must have platform signature to use this method.
     *
     * @param bundleOption Indicates the bundle name and uid of the application whose notifications are to be removed.
     * @param notificationId Indicates the id of the notification to remove.
     * @param label Indicates the label of the notification to remove.
     * @return Returns remove notification result.
     */
    ErrCode RemoveNotification(
        const NotificationBundleOption &bundleOption, const int32_t notificationId, const std::string &label);

    /**
     * @brief Removes a specified removable notification of other applications.
     * @note Your application must have platform signature to use this method.
     *
     * @param bundleOption Indicates the bundle name and uid of the application whose notifications are to be removed.
     * @return Returns remove notification result.
     */
    ErrCode RemoveAllNotifications(const NotificationBundleOption &bundleOption);

    /**
     * @brief Removes all removable notifications of a specified bundle.
     * @note Your application must have platform signature to use this method.
     *
     * @param bundleOption Indicates the bundle name and uid of the application whose notifications are to be removed.
     * @return Returns remove notifications result.
     */
    ErrCode RemoveNotificationsByBundle(const NotificationBundleOption &bundleOption);

    /**
     * @brief Removes all removable notifications in the system.
     * @note Your application must have platform signature to use this method.
     *
     * @return Returns remove notifications result.
     */
    ErrCode RemoveNotifications();

    /**
     * @brief Obtains all notification slots belonging to the specified bundle.
     *
     * @param bundleOption Indicates the bundle name and uid of the application.
     * @param slots Indicates a list of notification slots.
     * @return Returns get notification slots for bundle result.
     */
    ErrCode GetNotificationSlotsForBundle(
        const NotificationBundleOption &bundleOption, std::vector<sptr<NotificationSlot>> &slots);

    /**
     * @brief Updates all notification slots for the specified bundle.
     *
     * @param bundleOption Indicates the bundle name and uid of the application.
     * @param slots Indicates a list of new notification slots.
     * @return Returns update notification slots for bundle result.
     */
    ErrCode UpdateNotificationSlots(
        const NotificationBundleOption &bundleOption, const std::vector<sptr<NotificationSlot>> &slots);

    /**
     * @brief Updates all notification slot groups for the specified bundle.
     *
     * @param bundleOption Indicates the bundle name and uid of the application.
     * @param groups Indicates a list of new notification slot groups.
     * @return Returns update notification slot groups for bundle result.
     */
    ErrCode UpdateNotificationSlotGroups(
        const NotificationBundleOption &bundleOption, const std::vector<sptr<NotificationSlotGroup>> &groups);

    /**
     * @brief Obtains all active notifications in the current system. The caller must have system permissions to
     * call this method.
     *
     * @param notification Indicates all active notifications of this application.
     * @return Returns get all active notifications
     */
    ErrCode GetAllActiveNotifications(std::vector<sptr<Notification>> &notification);

    /**
     * @brief Obtains the active notifications corresponding to the specified key in the system. To call this method
     * to obtain particular active notifications, you must have received the notifications and obtained the key
     * via {Notification::GetKey()}.
     *
     * @param key Indicates the key array for querying corresponding active notifications.
     *            If this parameter is null, this method returns all active notifications in the system.
     * @param notification Indicates the set of active notifications corresponding to the specified key.
     * @return Returns get all active notifications result.
     */
    ErrCode GetAllActiveNotifications(
        const std::vector<std::string> key, std::vector<sptr<Notification>> &notification);

    /**
     * @brief Checks whether a specified application has the permission to publish notifications. If bundle specifies
     * the current application, no permission is required for calling this method. If bundle specifies another
     * application, the caller must have system permissions.
     *
     * @param bundleOption Indicates the bundle name and uid of the application.
     * @param allowed True if the application has permissions; returns false otherwise.
     * @return Returns is allowed notify result.
     */
    ErrCode IsAllowedNotify(const NotificationBundleOption &bundleOption, bool &allowed);

    /**
     * @brief Sets whether to allow all applications to publish notifications on a specified device. The caller must
     * have system permissions to call this method.
     *
     * @param deviceId Indicates the ID of the device running the application. At present, this parameter can only
     *                 be null or an empty string, indicating the current device.
     * @param enabled Specifies whether to allow all applications to publish notifications. The value true
     *                indicates that notifications are allowed, and the value false indicates that notifications are not
     *                allowed.
     * @return Returns set notifications enabled for all bundles result.
     */
    ErrCode SetNotificationsEnabledForAllBundles(const std::string &deviceId, bool enabled);

    /**
     * @brief Sets whether to allow the current application to publish notifications on a specified device. The caller
     * must have system permissions to call this method.
     *
     * @param deviceId Indicates the ID of the device running the application. At present, this parameter can
     *                 only be null or an empty string, indicating the current device.
     * @param enabled Specifies whether to allow the current application to publish notifications. The value
     *                true indicates that notifications are allowed, and the value false indicates that
     *                notifications are not allowed.
     * @return Returns set notifications enabled for default bundle result.
     */
    ErrCode SetNotificationsEnabledForDefaultBundle(const std::string &deviceId, bool enabled);

    /**
     * @brief Sets whether to allow a specified application to publish notifications on a specified device. The caller
     * must have system permissions to call this method.
     *
     * @param bundleOption Indicates the bundle name and uid of the application.
     * @param deviceId Indicates the ID of the device running the application. At present, this parameter can only
     *                 be null or an empty string, indicating the current device.
     * @param enabled Specifies whether to allow the given application to publish notifications. The value
     *                true indicates that notifications are allowed, and the value false indicates that notifications
     *                are not allowed.
     * @return Returns set notifications enabled for specified bundle result.
     */
    ErrCode SetNotificationsEnabledForSpecifiedBundle(
        const NotificationBundleOption &bundleOption, const std::string &deviceId, bool enabled);

    /**
     * @brief Sets whether to allow a specified application to to show badge.
     *
     * @param bundleOption Indicates the bundle name and uid of the application.
     * @param enabled Specifies whether to allow the given application to show badge.
     * @return Returns set result.
     */
    ErrCode SetShowBadgeEnabledForBundle(const NotificationBundleOption &bundleOption, bool enabled);

    /**
     * @brief Obtains the flag that whether to allow a specified application to to show badge.
     *
     * @param bundleOption Indicates the bundle name and uid of the application.
     * @param enabled Specifies whether to allow the given application to show badge.
     * @return Returns get result.
     */
    ErrCode GetShowBadgeEnabledForBundle(const NotificationBundleOption &bundleOption, bool &enabled);

    /**
     * @brief Obtains the flag that whether to allow the current application to to show badge.
     *
     * @param enabled Specifies whether to allow the given application to show badge.
     * @return Returns get result.
     */
    ErrCode GetShowBadgeEnabled(bool &enabled);

    /**
     * @brief Cancels the notification of the specified group of this application.
     *
     * @param groupName the specified group name.
     * @return Returns cancel group result.
     */
    ErrCode CancelGroup(const std::string &groupName);

    /**
     * @brief Removes the notification of the specified group of the specified application.
     *
     * @param bundleOption Indicates the bundle name and uid of the specified application.
     * @param groupName Indicates the specified group name.
     * @return Returns remove group by bundle result.
     */
    ErrCode RemoveGroupByBundle(const NotificationBundleOption &bundleOption, const std::string &groupName);

    /**
     * @brief Sets the do not disturb time.
     * @note Your application must have system signature to call this method.
     *
     * @param doNotDisturbDate Indicates the do not disturb time to set.
     * @return Returns set do not disturb time result.
     */
    ErrCode SetDoNotDisturbDate(const NotificationDoNotDisturbDate &doNotDisturbDate);

    /**
     * @brief Obtains the do not disturb time.
     * @note Your application must have system signature to call this method.
     *
     * @param doNotDisturbDate Indicates the do not disturb time to get.
     * @return Returns set do not disturb time result.
     */
    ErrCode GetDoNotDisturbDate(NotificationDoNotDisturbDate &doNotDisturbDate);

    /**
     * @brief Obtains the flag that whether to support do not disturb mode.
     *
     * @param doesSupport Specifies whether to support do not disturb mode.
     * @return Returns check result.
     */
    ErrCode DoesSupportDoNotDisturbMode(bool &doesSupport);

    /**
     * @brief Checks if the device supports distributed notification.
     *
     * @param enabled True if the device supports distributed notification; false otherwise.
     * @return Returns is distributed enabled result.
     */
    ErrCode IsDistributedEnabled(bool &enabled);

    /**
     * @brief Sets whether the device supports distributed notifications.
     *
     * @param enable Specifies whether to enable the device to support distributed notification.
     *               The value true indicates that the device is enabled to support distributed notifications, and
     *               the value false indicates that the device is forbidden to support distributed notifications.
     * @return Returns enable distributed result.
     */
    ErrCode EnableDistributed(const bool enabled);

    /**
     * @brief Sets whether an application supports distributed notifications.
     *
     * @param bundleOption Indicates the bundle name and uid of an application.
     * @param enabled Specifies whether to enable an application to support distributed notification.
     *                The value true indicates that the application is enabled to support distributed notifications,
     *                and the value false indicates that the application is forbidden to support distributed
     *                notifications.
     * @return Returns enable distributed by bundle result.
     */
    ErrCode EnableDistributedByBundle(const NotificationBundleOption &bundleOption, const bool enabled);

    /**
     * @brief Sets whether this application supports distributed notifications.
     *
     * @param enabled Specifies whether to enable this application to support distributed notification.
     *                The value true indicates that this application is enabled to support distributed notifications,
     *                and the value false indicates that this application is forbidden to support distributed
     *                notifications.
     * @return Returns enable distributed self result.
     */
    ErrCode EnableDistributedSelf(const bool enabled);

    /**
     * @brief Checks whether an application supports distributed notifications.
     *
     * @param bundleOption Indicates the bundle name and uid of an application.
     * @param enabled True if the application supports distributed notification; false otherwise.
     * @return Returns is distributed enabled by bundle result.
     */
    ErrCode IsDistributedEnableByBundle(const NotificationBundleOption &bundleOption, bool &enabled);

    /**
     * @brief Obtains the device remind type.
     * @note Your application must have system signature to call this method.
     *
     * @param remindType Indicates the device remind type to get.
     * @return Returns get device reminder type result.
     */
    ErrCode GetDeviceRemindType(NotificationConstant::RemindType &remindType);

    /**
     * @brief Publishes a continuous task notification.
     *
     * @param request Indicates the NotificationRequest object for setting the notification content.
     *                This parameter must be specified.
     * @return Returns publish continuous task notification result.
     */
    ErrCode PublishContinuousTaskNotification(const NotificationRequest &request);

    /**
     * @brief Cancels a published continuous task notification matching the specified label and notificationId.
     *
     * @param label Indicates the label of the continuous task notification to cancel.
     * @param notificationId Indicates the ID of the continuous task notification to cancel.
     * @return Returns cancel continuous task notification result.
     */
    ErrCode CancelContinuousTaskNotification(const std::string &label, int32_t notificationId);

    /**
     * @brief Obtains whether the template is supported by the system.
     *
     * @param support whether is it a system supported template.
     * @return Returns check result.
     */
    ErrCode IsSupportTemplate(const std::string &templateName, bool &support);

    /**
     * @brief Resets ans manager proxy when OnRemoteDied called.
     */
    void ResetAnsManagerProxy();

    /**
     * @brief Obtains specific informations via specified dump option.
     *
     * @param dumpOption Indicates the specified dump option.
     * @param dumpInfo Indicates the container containing informations.
     * @return Returns check result.
     */
    ErrCode ShellDump(const std::string &dumpOption, std::vector<std::string> &dumpInfo);

    /**
     * @brief Publishes a scheduled reminder.
     *
     * @param reminder Indicates a reminder.
     * @return Returns publish result.
     */
    ErrCode PublishReminder(ReminderRequest &reminder);

    /**
     * @brief Cancels a specified reminder.
     *
     * @param reminderId Indicates reminder Id.
     * @return Returns cancel result.
     */
    ErrCode CancelReminder(const int32_t reminderId);

    /**
     * @brief Cancels all reminders of current third part application.
     *
     * @return Returns cancel result.
     */
    ErrCode CancelAllReminders();

    /**
     * @brief Obtains all valid reminder notifications set by the current application.
     *
     * @param[out] validReminders Indicates the vector to store the result.
     * @return Returns get valid reminders result.
     */
    ErrCode GetValidReminders(std::vector<sptr<ReminderRequest>> &validReminders);

    /**
     * @brief Checks whether this application has permission to publish notifications under the user.
     *
     * @param userId Indicates the userId of the application.
     * @param allowed True if the application has permissions; returns false otherwise.
     * @return Returns get allowed result.
     */
    ErrCode IsAllowedNotify(const int32_t &userId, bool &allowed);

    /**
     * @brief Sets whether to allow all applications to publish notifications on a specified user.
     * The caller must have system permissions to call this method.
     *
     * @param userId Indicates the ID of the user running the application.
     * @param enabled Specifies whether to allow all applications to publish notifications. The value true
     *                indicates that notifications are allowed, and the value false indicates that notifications
     *                are not allowed.
     * @return Returns set notifications enabled for all bundles result.
     */
    ErrCode SetNotificationsEnabledForAllBundles(const int32_t &userId, bool enabled);

    /**
     * @brief Removes notifications under specified user.
     * @note Your application must have platform signature to use this method.
     *
     * @param userId Indicates the ID of user whose notifications are to be removed.
     * @return Returns remove notification result.
     */
    ErrCode RemoveNotifications(const int32_t &userId);

    /**
     * @brief Sets the do not disturb time on a specified user.
     * @note Your application must have system signature to call this method.
     *
     * @param userId Indicates the specific user.
     * @param doNotDisturbDate Indicates the do not disturb time to set.
     * @return Returns set do not disturb time result.
     */
    ErrCode SetDoNotDisturbDate(const int32_t &userId, const NotificationDoNotDisturbDate &doNotDisturbDate);

    /**
     * @brief Obtains the do not disturb time on a specified user.
     * @note Your application must have system signature to call this method.
     *
     * @param userId Indicates the specific user.
     * @param doNotDisturbDate Indicates the do not disturb time to get.
     * @return Returns set do not disturb time result.
     */
    ErrCode GetDoNotDisturbDate(const int32_t &userId, NotificationDoNotDisturbDate &doNotDisturbDate);

    /**
     * Set whether the application slot is enabled.
     *
     * @param bundleOption Indicates the bundle name and uid of the application.
     * @param slotType Indicates type of slot.
     * @param enable the type of slot enabled.
     * @return Returns get slot number by bundle result.
     */
    ErrCode SetEnabledForBundleSlot(
        const NotificationBundleOption &bundleOption, const NotificationConstant::SlotType &slotType, bool enabled);

    /**
     * Obtains whether the application slot is enabled.
     *
     * @param bundleOption Indicates the bundle name and uid of the application.
     * @param slotType Indicates type of slot.
     * @param enable the type of slot enabled to get.
     * @return Returns get slot number by bundle result.
     */
    ErrCode GetEnabledForBundleSlot(
        const NotificationBundleOption &bundleOption, const NotificationConstant::SlotType &slotType, bool &enabled);
private:
    /**
     * @brief Gets Ans Manager proxy.
     *
     * @return Returns true if succeed; returns false otherwise.
     */
    bool GetAnsManagerProxy();

    /**
     * @brief Checks if the MediaContent can be published.
     *
     * @param request Indicates the specified request.
     * @return Returns true if the MediaContent can be published; returns false otherwise.
     */
    bool CanPublishMediaContent(const NotificationRequest &request) const;

    /**
     * @brief Checks whether the picture size exceeds the limit in PixelMap.
     *
     * @param pixelMap Indicates the specified image.
     * @param maxSize Indicates the limit size.
     * @return Returns true if the limit size is exceeded; returns false otherwise.
     */
    bool CheckImageOverSizeForPixelMap(
        const std::shared_ptr<Media::PixelMap> &pixelMap, uint32_t maxSize);

    /**
     * @brief Checks whether the picture size exceeds the limit in NotificationRequest's content.
     *
     * @param request Indicates the specified request.
     * @return Returns the ErrCode.
     */
    ErrCode CheckImageSizeForContent(const NotificationRequest &request);

    /**
     * @brief Checks whether the picture size exceeds the limit.
     *
     * @param request Indicates the specified request.
     * @return Returns the ErrCode.
     */
    ErrCode CheckImageSize(const NotificationRequest &request);

    /**
     * @brief Checks whether the notification doesn't support distribution.
     *
     * @param type Indicates the specified NotificationContent::Type.
     * @return Returns true if the notification doesn't support distribution; returns false otherwise.
     */
    bool IsNonDistributedNotificationType(const NotificationContent::Type &type);

private:
    std::mutex mutex_;
    sptr<AnsManagerInterface> ansManagerProxy_;
    sptr<AnsManagerDeathRecipient> recipient_;
};
}  // namespace Notification
}  // namespace OHOS

#endif  // BASE_NOTIFICATION_ANS_STANDARD_FRAMEWORKS_ANS_CORE_INCLUDE_ANS_NOTIFICATION_H