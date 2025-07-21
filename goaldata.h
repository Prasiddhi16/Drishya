#ifndef GOALDATA_H
#define GOALDATA_H

#include <QString>
#include <QUuid> // Include QUuid for id generation if you want GoalData itself to handle new IDs

struct GoalData
{
    QString id;           // Unique ID (UUID from database)
    QString name;
    double incomeRequired;
    double downpayment;
    int duration;         // Duration in months
    int slotIndex;        // Tracks its position in the UI (1-6), not saved to DB but useful in memory

    // Default constructor (sets numeric values to 0, strings to empty)
    GoalData() : incomeRequired(0.0), downpayment(0.0), duration(0), slotIndex(0) {}

    // Constructor for setting all values (useful when loading from DB or creating new data)
    GoalData(const QString& id_val, const QString& name_val, double income_val, double dp_val, int duration_val, int slot_val = 0)
        : id(id_val), name(name_val), incomeRequired(income_val), downpayment(dp_val), duration(duration_val), slotIndex(slot_val) {}

    // Convenience constructor for setting basic details (e.g., from an input dialog)
    // Note: 'id' and 'slotIndex' would typically be handled by the calling class (Visions)
    GoalData(const QString& name_val, double income_val, double dp_val, int duration_val)
        : name(name_val), incomeRequired(income_val), downpayment(dp_val), duration(duration_val), slotIndex(0) {}


    // Helper to check if a GoalData object is "empty" (represents an unused slot)
    bool isEmpty() const {
        // A goal is considered empty if its ID is empty AND its name is empty
        // This prevents considering goals with just 0 amounts as "empty" if they have a name/ID.
        return id.isEmpty() && name.isEmpty();
    }
};
#endif // GOALDATA_H
